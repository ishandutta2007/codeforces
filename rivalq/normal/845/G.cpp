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
 		set<pair<int,pii>>rem;
 		vector<vector<pii>>g(n+1);
 		rep(i,0,m){
 			int a,b,w; cin >> a >> b >> w;
 			g[a].push_back({b,w});
 			g[b].push_back({a,w});
 		}
 		vector<int>depth(n+1),vis(n+1);
 		function<void(int,int)>dfs = [&](int u,int p){
 			vis[u] = 1;
 			for(auto [i,w]:g[u]){
 				if(i == p)continue;
 				if(!vis[i]){
 					depth[i] = depth[u]^w;
 					dfs(i,u);
 				}else{
 					rem.insert({w,{i,u}});
 				}
 			}
 		};
 		dfs(1,-1);
 		vector<int>basis(30);
 		auto add = [&](int mask){
 			for(int j = 29; j >= 0; j--){
 				if((1 << j)&mask){
 					if(basis[j] == 0){
 						basis[j] = mask;
 						break;
 					}else{
 						mask ^= basis[j];
 					}
 				}
 			}
 		};

 		for(auto i:rem){
 			int w = i.x;
 			int u = i.y.x;
 			int v = i.y.y;
 			add(w^depth[u]^depth[v]);
 		}
 		int ans = depth[n];
 		for(int j = 29; j >= 0; j--){
 			if((1 << j)&ans){
 				if(basis[j]){
 					ans ^= basis[j];
 				}
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}