// better, faster, stronger
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<int, pii> pi3; // -> dp vertice last_w

const int maxn = 1e5 + 10, maxw = 55, inf = 15e8;

vector<pii> v[maxn];
int dp[maxn][maxw];
bool mark[maxn][maxw];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	int a, b, c;
	cin >> a >> b >> c;
	v[a].PB({b, c});
	v[b].PB({a, c});
    }
    for(int i = 0; i < maxn; i++){
	for(int j = 0; j < maxw; j++)
	    dp[i][j] = inf;
    }
    dp[1][0] = 0;
    priority_queue<pi3, vector<pi3>, greater<pi3>> pq;
    pq.push({0, {1, 0}});
    
    while(sz(pq)){
	auto [u, w] = pq.top().S;
	pq.pop();
	if(mark[u][w])
	    continue;
	mark[u][w] = 1;
	for(auto [y, c] : v[u]){
	    int tmp = dp[u][w] + c * c + 2 * w * c;
	    int nw = (w == 0 ? c : 0);
	    if(dp[y][nw] > tmp)
		dp[y][nw] = tmp, pq.push({tmp, {y, nw}});
	}
    }
    for(int i = 1; i <= n; i++){
	if(dp[i][0] == inf)
	    cout << -1 << " ";
	else
	    cout << dp[i][0] << " ";
    }
    return cout << endl, 0;
}