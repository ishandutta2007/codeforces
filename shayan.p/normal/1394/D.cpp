// And you curse yourself for things you never done
// Shayan.P  2020-08-12

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;    

vector<int> v[maxn];
int a[maxn], b[maxn], in[maxn], out[maxn];
bool mark[maxn];

ll dp[2][maxn], ans[maxn];

void dfs(int u){
    mark[u] = 1;
    vector<ll> vec;
    ll sm = 0;
    for(int y : v[u]){
	if(!mark[y]){
	    dfs(y);
	    sm+= dp[0][y];
	    vec.PB(dp[1][y] - dp[0][y]);
	}
    }
    ans[u] = dp[0][u] = dp[1][u] = inf;
    sort(vec.begin(), vec.end());
    for(int i = 0; i <= sz(vec); i++){
	int IN = in[u] + i, OUT = out[u] + sz(vec) - i;
	ans[u] = min(ans[u], sm + 1ll * a[u] * max(IN, OUT));
	dp[0][u] = min(dp[0][u], sm + 1ll * a[u] * max(IN+1, OUT));
	dp[1][u] = min(dp[1][u], sm + 1ll * a[u] * max(IN, OUT+1));	
	if(i != sz(vec))
	    sm+= vec[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
	cin >> a[i];
    for(int i = 1; i <= n; i++)
	cin >> b[i];    
    for(int i = 1; i <= n-1; i++){
	int u, y;
	cin >> u >> y;
	if(b[u] > b[y])
	    swap(u, y);
	if(b[u] == b[y])
	    v[u].PB(y), v[y].PB(u);
	else
	    out[u]++, in[y]++;	    
    }
    ll ANS = 0;
    for(int i = 1; i <= n; i++){
	if(!mark[i])
	    dfs(i), ANS+= ans[i];	
    }
    return cout << ANS << endl, 0;
}