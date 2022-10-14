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
 		vector<vector<int>>g(n+1);
 		vector<int>a(n+1);
 		rep(i,1,n+1){
 			cin >> a[i];
 		}
 		int d = 0;
 		rep(i,1,n+1){
 			int t;cin >> t;
 			a[i] = t - a[i];
 			d += a[i];
 		}
 		rep(i,1,m+1){
 			int a,b; cin >> a >> b;
 			g[a].push_back(b);
 			g[b].push_back(a);
 		}
 		if(d%2){
 			cout << "NO" << endl;
 			return 0;
 		}
 		vector<int>vis(n+1);
 		vector<int>dep(n+1);
 		function<int(int,int)> dfs = [&](int u,int p){
 			int s = a[u];
 			vis[u] = 1;
 			for(auto i:g[u]){
 				if(i == p)continue;
 				if(!vis[i]){
 					dep[i] = dep[u] + 1;
 					s -= dfs(i,u);
 				}
 			}
 			vis[u] = 2;
 			return s;
 		};
 		if(dfs(1,1) == 0){
 			cout << "YES" << endl;
 			return 0;
 		}
 		bool odd = 0;
 		int s = 0;
 		for(int i = 1; i <= n; i++){
 			vis[i] = 0,dep[i] = 0;
 		}
 		vector<int>q = {1};
 		vis[1] = 1;
 		for(int i = 0; i < q.size(); i++){
 			int v = q[i];
 			if(dep[v]%2 == 0)s += a[i];
 			else s -= a[i];
 			for(auto j:g[v]){
 				if(!vis[j]){
 					dep[j] = 1^dep[v];
 					q.push_back(j);
 					vis[j] = 1;
 				}else{
 					if(dep[j] == dep[v])odd = 1;
 				}
 			}
 		}
 		if(s == 0 or odd){
 			cout << "YES" << endl;
 		}else{
 			cout << "NO" << endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}