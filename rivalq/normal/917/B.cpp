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

bool dp[105][105][30][2];
bool vis[105][105][30][2];

int solve(){
 		int n,m; cin >> n >> m;
 		vector<vector<char>>g(n + 1,vector<char>(n + 1,'0'));
 		for(int i = 1; i <= m; i++){
 			int u,v; cin >> u >> v;
 			cin >> g[u][v];
 		}

 		function<int(int,int,int,int)> dfs = [&](int u,int v,int c1,int turn){
 			if(vis[u][v][c1][turn])return dp[u][v][c1][turn];
 			bool  &ans = dp[u][v][c1][turn];
 			vis[u][v][c1][turn] = true;
 			if(turn == 0){
 				for(int j = 1; j <= n; j++){
 					if(g[u][j] != '0' and g[u][j] - 97 >= c1){
 						ans |= (!dfs(j,v,g[u][j] - 97,1));
 					}
 				}
 			}else{
 				for(int j = 1; j <= n; j++){
 					if(g[v][j] != '0' and g[v][j] - 97 >= c1){
 						ans |= (!dfs(u,j,g[v][j] - 97,0));
 					}
 				}
 			}
 			return ans;
 		};
 		for(int i = 1; i <= n; i++){
 			for(int j = 1; j <= n; j++){
 				if(dfs(i,j,0,0)){
 					cout << "A";
 				}else{
 					cout << "B";
 				}
 			}
 			cout << endl;
 		}

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