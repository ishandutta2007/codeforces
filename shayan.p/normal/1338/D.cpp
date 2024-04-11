// Never let them see you bleed...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int dp[maxn][2], ans;
vector<int> v[maxn];

void dfs(int u, int par = -1){
    vector<int> vec1, vec0;
    
    int child = 0;
    for(int y : v[u]){
	if(y != par){
	    dfs(y, u);
	    dp[u][1] = max(dp[u][1], dp[y][0]);
	    dp[u][0] = max({dp[u][0], dp[y][0], dp[y][1]});
	    vec1.PB(dp[y][0]);
	    vec0.PB(max(dp[y][0], dp[y][1]));
	    child++;
	}
    }
    sort(vec1.begin(), vec1.end(), greater<int>());
    sort(vec0.begin(), vec0.end(), greater<int>());    
    dp[u][1]++;
    if(child > 0)
	dp[u][0]+= child-1;
    if(sz(vec0) >= 2)
	ans = max(ans, vec0[0] + vec0[1] + max(int(0), child - 2) + (par != -1));
    if(sz(vec1) >= 2)
	ans = max(ans, vec1[0] + vec1[1] + 1);
    ans = max(ans, dp[u][0]);
    ans = max(ans, dp[u][1]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);	
    }
    dfs(1);
    return cout << ans << endl, 0;    
}