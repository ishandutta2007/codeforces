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
 		int n; cin >> n;
 		vector<vector<int>>g(n + 1);

 		for(int i = 2; i <= n; i++){
 			int u,v; cin >> u >> v;
 			g[u].push_back(v);
 			g[v].push_back(u);
 		}
 		auto get_msb = [&](int x){
 			for(int j = 19; j >= 0; j--){
 				if((1 << j) & x){
 					return j;
 				}
 			}
 			return -1LL;
 		};
 		vector<vector<int>> msb(20);
 		for(int i = 1; i <= n; i++){
 			msb[get_msb(i)].push_back(i);
 		}
 		vector<int>assign(n + 1);
 		vector<vector<int>>vec(2);
 		function<void(int,int,int)> dfs = [&](int u,int p,int l){
 			vec[l].push_back(u);
 			for(auto i:g[u]){
 				if(i != p){
 					dfs(i,u,l ^ 1);
 				}
 			}

 		};
 		dfs(1,1,0);
 		for(int j = 19; j >= 0; j--){
 			if(vec[0].size() < vec[1].size())swap(vec[0],vec[1]);
 			for(auto i:msb[j]){
 				assign[vec[0].back()] = i;
 				vec[0].pop_back();
 			}
 		}
 		for(int i = 1; i <= n; i++)cout << assign[i] << " ";
 		cout << endl;

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