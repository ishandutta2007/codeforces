#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};
 
	Dinic(int n) {
		edges.resize(n);
		this->n = n;
	}
 
	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			T flow;
			pt = std::vector<int>(n, 0);
			while(flow = dfs(src, sink)) {
				ans += flow;
			}
		}
		return ans;
	}
 
	void addEdge(int from, int to, T cap = 1) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, 0));
	}
private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;
 
	T dfs(int on, int sink, T flow = 1e9) {
		if(flow == 0) {
			return 0;
		} if(on == sink) {
			return flow;
		}
		for(; pt[on] < edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) {
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}
 
	bool bfs(int src, int sink) {
		h = std::vector<int>(n, n);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a : edges[on]) {
				if(list[a].cap == 0) {
					continue;
				}
				int to = list[a].to;
				if(h[to] > h[on] + 1) {
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] < n;
	}
};

int solve(){
 	int n,m;cin>>n>>m;
 	vector<int>val(n+1);
 	Dinic<int> base(n+3);
 	rep(i,1,n+1){
 		cin>>val[i];
 	}
 	int s=n+1,t=n+2;
 	rep(i,0,m){
 		int u,v;cin>>u>>v;
 		if(u%2)swap(u,v);// directed edge from left to right
 		base.addEdge(u,v,100);
 	}
 	map<int,map<int,int>>mp;
 	rep(i,1,n+1){
 		for(int j=2;j<=sqrt(val[i]);j++){
 			if(val[i]%j==0){
 				while(val[i]%j==0){
 					val[i]/=j;
 					mp[j][i]++;
 				}
 			}
 		}
 		if(val[i]>1){
 			mp[val[i]][i]++;
 		}
 	}	
 	int ans=0;
 	for(auto p:mp){
 		Dinic<int> base2=base;
 		for(auto i:p.y){
 			int u=i.x;
 			int c=i.y;
 			if(u%2==0){
 				base2.addEdge(s,u,c);
 			}
 			else{
 				base2.addEdge(u,t,c);
 			}
 		}
 		ans+=base2.maxFlow(s,t);
 	}
 	cout<<ans<<endl;
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