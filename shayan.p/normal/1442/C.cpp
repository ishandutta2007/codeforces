// Oh my lord I need you by my side...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e5 + 10, inf = 1e9, mod = 998244353;

pii bst[2 * maxn];
bool seen[2 * maxn];
vector<int> v[maxn][2];

const int MAX_LOG = 22;

int dp[maxn][MAX_LOG];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, m;
    cin >> n >> m;
    vector<pii> ed;
    for(int i = 0; i < m; i++){
	int a, b;
	cin >> a >> b;
	v[a][0].PB(b);
	v[b][1].PB(a);
	ed.PB({a, b});
    }
    {
	deque<pii> d;
	memset(dp, 63, sizeof dp);
	int INF = dp[0][0];
	dp[1][0] = 0;
	d.PB({1, 0});
	while(sz(d)){
	    int u = d[0].F, level = d[0].S;
	    d.pop_front();
	    for(int y : v[u][level & 1]){
		if(dp[y][level] == INF){
		    dp[y][level] = dp[u][level] + 1;
		    d.PB({y, level});
		}
	    }
	    if(level + 1 < MAX_LOG && dp[u][level + 1] == INF){
		dp[u][level + 1] = dp[u][level];
		d.push_front({u, level + 1});
	    }
	}

	int ans = inf;
	for(int i = 0; i < MAX_LOG; i++){
	    if(dp[n][i] != INF)
		ans = min(ans, dp[n][i] + (1<<i) - 1);
	}
	if(ans != inf){
	    return cout << ans << endl, 0;
	}	
    }
    
    memset(bst, 63, sizeof bst);
    priority_queue<pair<pii, int>, vector<pair<pii, int> >, greater< pair<pii, int> > > pq;
    bst[2] = {0, 0};
    pq.push({bst[2], 2});
    auto better = [&](int id, pii p){
		      if(bst[id] > p){
			  bst[id] = p;
			  pq.push({p, id});
		      }
		  };
    while(sz(pq)){
	int id = pq.top().S;
	pq.pop();
	int u = id >> 1, state = id & 1;
	if(seen[id])
	    continue;
	seen[id] = true;
	for(int y : v[u][state])
	    better(2 * y + state, (pii){bst[id].F, bst[id].S + 1}); 
	better(2 * u + (!state), (pii){bst[id].F + 1, bst[id].S});
    }
    pii ret = min(bst[2 * n], bst[2 * n + 1]);
    int ans = 1;
    for(int i = 0; i < ret.F; i++){
	ans = 2ll * ans % mod;
    }
    ans--;
    ans = (ans + ret.S) % mod;
    return cout << ans << endl, 0;
}