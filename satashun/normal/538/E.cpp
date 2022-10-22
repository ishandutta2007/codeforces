#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()

int n;
vector<int> g[200010];
int dp[200010]; //v->1
int dp2[200010]; //v->0
int dep[200010];
bool leaf[200010];

void pre(int v, int p, int d){
    dep[v] = d;
    leaf[v] = 1;
    for(int &to : g[v]) if(to != p){
	pre(to, v, d + 1);
	leaf[v] = 0;
    }
}

void dfs(int v, int p){
    if(leaf[v]){ dp[v] = 1, dp2[v] = 1; return ; }
    if(dep[v] & 1){
	dp2[v] = 300000;
	for(int &to : g[v]) if(to != p){
	    dfs(to, v);
	    dp[v] += dp[to]; 
	    dp2[v] = min(dp2[v], dp2[to]);
	}
    }else{
	dp[v] = 300000;
	for(int &to : g[v]) if(to != p){
	    dfs(to, v);
	    dp[v] = min(dp[v], dp[to]); 
	    dp2[v] += dp2[to];
	}	
    }
}

int main(){
    scanf("%d", &n);
    rep(i, n - 1){
	int a, b;
	scanf("%d %d", &a, &b); --a; --b;
	g[a].pb(b); g[b].pb(a);
    }
    pre(0, -1, 0);
    dfs(0, -1);

    int m = 0;
    rep(i, n) m += leaf[i];

    int lo = 1, hi = m + 1;
    while(hi - lo > 1){
	int mid = (hi + lo) / 2;
	if(dp[0] <= (m - mid + 1)) lo = mid;
	else hi = mid;
    }
    printf("%d ", lo);
    lo = 0, hi = m;
    while(hi - lo > 1){
	int mid = (hi + lo) / 2;
	if(dp2[0] <= mid) hi = mid;
	else lo = mid;
    }
    printf("%d\n", hi);
    return 0;
}