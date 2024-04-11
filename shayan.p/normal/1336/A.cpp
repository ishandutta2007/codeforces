// Never let them see you bleed...
// Shayan.P  2020-04-15

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

vector<int> v[maxn];
int h[maxn], cnt[maxn], SZ[maxn], pr[maxn];

void dfs(int u, int par = 0){
    pr[u] = par;
    cnt[u] = sz(v[u]) - (par != 0);
    SZ[u] = 1;
    h[u] = h[par]+1;
    for(int y : v[u]){
	if(y != par){
	    dfs(y, u);
	    SZ[u]+= SZ[y];
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    priority_queue<pii> pq;
    for(int i = 1; i <= n; i++){
	if(cnt[i] == 0)
	    pq.push({h[i]-1, i});
    }
    ll ans = 0;
    for(int w = 0; w < k; w++){
	ans+= pq.top().F;
	int u = pq.top().S;
	pq.pop();
	if(--cnt[pr[u]] == 0){
	    pq.push({-SZ[pr[u]] + h[pr[u]], pr[u]});
	}
    }
    return cout << ans << endl, 0;
}