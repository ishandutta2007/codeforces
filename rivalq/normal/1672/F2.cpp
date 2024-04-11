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
 		int n; cin >> n;
 		vector<int>a(n),b(n);
 		for(auto &i:a)cin >> i;
 		for(auto &i:b)cin >> i;
                map<int,int> mp;
                int mx = 0;
                int j = -1;
                for(auto i:a){
                        mp[i]++;
                        if(mp[i] > mx){
                                mx = mp[i];
                                j = i;
                        }
                }        
                // after removing j from graph of a_i -> b_i, graph should be acylic
                digraph<int> graph(n);
 		for(int i = 0; i < n; i++){
                        if(a[i] != j and b[i] != j){
                                if(a[i] == b[i]){
                                        cout << "WA" << endl;
                                        return 0;
                                }
                                graph.addEdge(a[i],b[i]);
                        }
 		}
                if(graph.topo_sort()){
                        cout << "AC" << endl;
                }else{
                        cout << "WA" << endl;
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