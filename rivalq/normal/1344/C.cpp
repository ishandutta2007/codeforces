// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 2e5 + 5;

vector<int>g[N];
int dp1[N],dp2[N];
int vis[N];

void dfs(int u,int dp[]){
	if(vis[u])return;
	dp[u] = u;
	vis[u] = 1;
	for(auto i:g[u]){
		if(vis[i] == 1){
			cout << -1 << endl;
			exit(0);
		}
		dfs(i,dp);
		mins(dp[u],dp[i]);
	}
	vis[u] = 2;
}

int solve(){
 		int n,m; cin >> n >> m;
 		vector<pii>edges(m);
 		rep(i,0,m){
 			cin >> edges[i];
 		}
 		for(int i = 0; i < m; i++){
 			g[edges[i].x].push_back({edges[i].y});
 		}
 		for(int i = 1; i <= n; i++){
 			dfs(i,dp1);
 		}
 		for(int i = 1; i <= n; i++){
 			g[i].clear();
 		}
 		memset(vis,0,sizeof(vis));
 		for(int i = 0; i < m; i++){
 			g[edges[i].y].push_back({edges[i].x});
 		}
 		for(int i = 1; i <= n; i++){
 			dfs(i,dp2);
 		}
 		string s;
 		int cnt = 0;
 		for(int i = 1; i <= n; i++){
 			if(min(dp1[i],dp2[i]) == i)cnt++,s.push_back('A');
 			else s.push_back('E');
 		}
 		cout << cnt << endl;
 		cout << s << endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}