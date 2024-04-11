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




template<typename T>
class digraph{

public:

	vector<vector<T>>g,gt,cond;
	vector<T>order;
	vector<T>comp;
	int n;
	digraph(int n):n(n){
		g.resize(n+1),gt.resize(n+1);
		comp.resize(n+1);
	}
	void addEdge(int u,int v){
		g[u].push_back(v);
		gt[v].push_back(u);
	}
	bool topo_sort(){
		vector<int> used(n+1);
		bool dag = 1;
		function<void(int)>dfs=[&](int u){
			used[u] = 1;
			for(auto i:g[u]){
				if(used[i]==1){
					dag = 0;
				}
				else if(used[i]==0){
					dfs(i);
				}
			}
			used[u] = 2;
			order.push_back(u);
		};
		for(int i=1;i<=n;i++){
			if(used[i]==0)dfs(i);
		}
		return dag;
	}
	int scc(){
		topo_sort();
		vector<int>used(n+1);
		int ptr = 0;
		function<void(int)>dfs=[&](int u){
			comp[u]=ptr;
			used[u]=1;
			for(auto i:gt[u]){
				if(!used[i]){
					dfs(i);
				}
			}
		};
		while(!order.empty()){
			int u = order.back();order.pop_back();
			if(used[u])continue;
			ptr++;
			dfs(u);
		}
		return ptr;
	}
	int cond_graph(){
		int m = scc();
		cond.resize(m+1);
		for(int i=1;i<=n;i++){
			for(auto j:g[i]){
				if(comp[i]==comp[j])continue;
				cond[comp[i]].push_back(comp[j]);	
			}
		}
		return m;	
	}
};





int solve(){
 		int n,m; cin >> n >> m;

 		
 		vector<vector<int>>a(n+1,vector<int>(m+1));
 		vector<vector<int>>down(n+1,vector<int>(m+1));
 		int cnt = 0;
 		map<pii,int>mp;
 		rep(i,1,n+1){
 			rep(j,1,m+1){
 				char c; cin >> c;
 				if(c == '#'){
 					a[i][j] = 1;
 					mp[{i,j}] = ++cnt;
 				}
 			}
 		}
 		digraph<int>g(cnt);
 		auto f = [&](int i,int j){
 			return mp[{i,j}];
 		};

 		for(int j = 1; j <= m; j++){

 			for(int i = n - 1; i >= 1; i--){
 				if(a[i + 1][j]){
 					down[i][j] = i + 1;
 				}else{
 					down[i][j] = down[i + 1][j];
 				}
 			}
 		}

 		for(int i = 1; i <= n; i++){
 			for(int j = 1; j <= m; j++){
 				if(a[i][j] == 0)continue;
 				if(down[i][j]){
 					g.addEdge(f(i,j),f(down[i][j],j));
 				}
 				if(i - 1 >= 1){
 					if(a[i - 1][j]){
 						g.addEdge(f(i,j),f(i-1,j));
 					}
 				}
 				if(j - 1 >= 1){
 					if(a[i][j - 1]){
 						g.addEdge(f(i,j),f(i,j - 1));
 					}else if(down[i][j-1]){
 						g.addEdge(f(i,j),f(down[i][j - 1],j - 1));
 					}
 				}
 				if(j + 1 <= m){
 					if(a[i][j + 1]){
 						g.addEdge(f(i,j),f(i,j + 1));
 					}else if(down[i][j + 1]){
 						g.addEdge(f(i,j),f(down[i][j + 1],j + 1));
 					}
 				}
 			}
 		}
 		


 		int k = g.cond_graph();
 		int ans = 0;
 		vector<int>in(k+1);
 		for(int i = 1; i <= k; i++){
 			for(auto j:g.cond[i]){
 				in[j]++;
 			}
 		}
 		for(int i = 1; i <= k; i++){
 			if(in[i] == 0)ans++;
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