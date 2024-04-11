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
	vector<vector<T>>rev;
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
		rev.resize(m+1);
		cond.resize(m+1);
		for(int i=1;i<=n;i++){
			rev[comp[i]].push_back(i);
			for(auto j:g[i]){
				if(comp[i]==comp[j])continue;
				cond[comp[i]].push_back(comp[j]);	
			}
		}
		return m;	
	}
};





int solve(){
 		int n; cin >> n;
 		digraph<int>g(n);
 		rep(i,1,n+1){
 			int p; cin >> p;
 			g.addEdge(i,p);
 		}
 		int m = g.cond_graph();
 		if(m == 1){
 			cout << 0 << endl;
 			return 0;
 		}
 		set<int>sources,sinks;
 		int num_sources = 0,num_sinks = 0;
 		vector<int>in(m+1),out(m+1),vis(m+1);
 		vector<vector<int>>tran(m+1);
 		for(int i = 1; i <= m; i++){
 			
 			for(auto j:g.cond[i]){
 				out[i]++;
 				in[j]++;
 				tran[j].push_back(i);
 			}
 		}	
 		for(int i = 1; i <= m; i++){
 			if(in[i] == 0){
 				sources.insert(i);
 				num_sources++;
 			}	
 			if(out[i] == 0){
 				sinks.insert(i);
 				num_sinks++;
 			}	
 		}
 		bool swap_ = 0;
 		if(num_sources > num_sinks){
 			swap_ = 1;
 			swap(num_sinks,num_sources);
 			swap(sources,sinks);
 			swap(tran,g.cond);
 		}	

 		int w = -1;
 		bool found = false;
 		function<void(int)>dfs = [&](int u){
 			if(vis[u])return;
 			if(sinks.count(u)){
 				w = u;
 				found = true;
 			}
 			vis[u] = 1;
 			for(auto j:g.cond[u]){
 				if(!found){
 					dfs(j);
 				}
 			}
 		};

 		vector<int>s,t;

 		for(auto i:sources){
 			if(!vis[i]){
 				w = -1;
 				found = false;
 				dfs(i);
 				if(w > 0){
 					s.push_back(i);
 					t.push_back(w);
 				}
 			}
 		}

 		int p = sz(s);

 		
 		
 		for(int i = 0; i < p; i++){
 			sinks.erase(t[i]);
 			sources.erase(s[i]);
 		}

 		for(auto i:sinks){
 			t.push_back(i);
 		}
 		for(auto i:sources){
 			s.push_back(i);
 		}
 		

		vector<pii>alpha_edges;
 		for(int i = 0; i + 1 < p; i++){
 			alpha_edges.push_back({t[i],s[i+1]});
 		}

 		for(int i = p; i < num_sources;i++){
 			alpha_edges.push_back({t[i],s[i]});
 		}	

 		if(num_sinks == num_sources){
 			alpha_edges.push_back({t[p-1],s[0]});
 		}
 		else if(num_sources < num_sinks){
 			alpha_edges.push_back({t[p-1],t[num_sources]});
 			for(int i = num_sources + 1; i < num_sinks;i++){
 				alpha_edges.push_back({t[i-1],t[i]});
 			}
 			alpha_edges.push_back({t[num_sinks-1],s[0]});
 		}
 		

 		cout << alpha_edges.size() << endl;
 		for(auto [u,v]:alpha_edges){
 			if(swap_){
 				cout << g.rev[v][0] << " " << g.rev[u][0] << endl;
 			}
 			else{
 				cout << g.rev[u][0] << " " << g.rev[v][0] << endl;	
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