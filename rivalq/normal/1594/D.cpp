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


int solve(){
 		int n,m; cin >> n >> m;
 		vector<vector<pii>> g(n + 1);
 		for(int i = 0; i < m; i++){
 			int u,v; cin >> u >> v;
 			string s; cin >> s;
 			int t = (s[0] == 'i');
 			g[u].push_back({v,t});
 			g[v].push_back({u,t});
 		} 
 		int ans = 0;
 		vector<int> vis(n + 1, -1);
 		for(int i = 1; i <= n; i++){
 			if(vis[i] == -1){
 				vector<int> q = {i};
 				vector<int> c(2);
 				vis[i] = 0;
 				for(int i = 0; i < q.size(); i++){
 					int u = q[i];
 					c[vis[u]]++;
 					for(auto [j,w]:g[u]){
 						if(vis[j] != -1){
 							if((vis[j]^vis[u]) != w){
 								cout << "-1" << endl;
 								return 0;
 							}
 						}
 						else{
 							vis[j] = (w^vis[u]);
 							q.push_back(j);
 						}
 					}
 				}
 				ans += max(c[0],c[1]);
 			}
 		}
 		cout << ans << endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}