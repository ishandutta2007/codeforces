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

	vector<vector<pii>>g,gt,cond;
	vector<T>order;
	vector<T>comp;
	vector<T>d;
	vector<T>res;		
	int n;
	digraph(int n):n(n){
		g.resize(n+1),gt.resize(n+1);
		comp.resize(n+1);
		d.resize(n+1);
		res.resize(n+1);
	}
	void addEdge(int u,int v,int w){
		g[u].push_back({v,w});
		gt[v].push_back({u,w});
	}
	bool topo_sort(){
		vector<int> used(n+1);
		bool dag = 1;
		function<void(int)>dfs=[&](int u){
			used[u] = 1;
			for(auto i:g[u]){
				if(used[i.x]==1){
					dag = 0;
				}
				else if(used[i.x]==0){
					dfs(i.x);
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
		function<void(int,int)>dfs=[&](int u,int h){
			comp[u]=ptr;
			used[u]=1;
			d[u] = h;
			for(auto [i,l]:gt[u]){
				if(used[i] and comp[i] == ptr){
					int x = abs(d[u] - d[i] + l);
					res[ptr] = gcd(res[ptr],x);
				}
				else if(!used[i]){ 
					dfs(i,h+l);
				}			
			}
		};
		while(!order.empty()){
			int u = order.back();order.pop_back();
			if(used[u])continue;
			ptr++;
			dfs(u,0);
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
 		digraph<int>g(n);
 		rep(i,1,m+1){
 			int a,b,l;
 			cin >> a >> b >> l;
 			g.addEdge(a,b,l);
 		}
 		g.scc();
 		int q; cin >> q;
 		rep(i,0,q){
 			int u,s,t; cin >> u >> s >> t;
 			if(s%gcd(t,g.res[g.comp[u]]) == 0){
 				cout << "YES" << endl;
 			}else{
 				cout << "NO" << endl;
 			}
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