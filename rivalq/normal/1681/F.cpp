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


//dsu with roll backs
struct dsu_save{
       int u,v,rnku,rnkv;
       dsu_save(){}
       dsu_save(int v,int u,int rnku,int rnkv):v(v),u(u),rnku(rnku),rnkv(rnkv){}
};
struct dsu_with_rollbacks{
       vector<int>p,rank;
       int cnt=0;
       stack<dsu_save>stk;
       dsu_with_rollbacks(){}
       dsu_with_rollbacks(int n){
       	   p.resize(n+1);rank.resize(n+1);
       	   for(int i=1;i<=n;i++)p[i]=i,rank[i]=1;
       	   cnt=n;
       }
       int root(int x){
       	  return (p[x]==x)?x:root(p[x]);
       } 
       bool merge(int x,int y){
       	    int px=root(x);
       	    int py=root(y);
       	    if(px==py)return 0;
       	    cnt--;
       	    if(rank[py]>rank[px])swap(px,py);
       	    stk.push(dsu_save(px,py,rank[py],rank[px]));
       	    p[py]=px;
       	    rank[px] += rank[py];
       	    rank[py] = 0;
       	    return 1;
       }
       void roll_back(){
       	    if(stk.empty())return;
       	    dsu_save dsu=stk.top();stk.pop();
       	    cnt++;
       	    p[dsu.u]=dsu.u;
       	    p[dsu.v]=dsu.v;
       	    rank[dsu.u]=dsu.rnku;
       	    rank[dsu.v]=dsu.rnkv;
       }
};

int solve(){
 		int n; cin >> n;
 		vector<vector<pii>>edges(n + 1);
 		for(int i = 1; i < n; i++){
 			int u,v,x; cin >> u >> v >> x;
 			edges[x].push_back({u,v});
 		}
 		auto dsu = dsu_with_rollbacks(n);

 		int ans = 0;
 		function<void(int,int)> dfs = [&](int l,int r){
 			if(l == r){
 				for(auto [u,v]:edges[l]){
 					u = dsu.root(u);
 					v = dsu.root(v);
 					ans += dsu.rank[u]*dsu.rank[v];
 				}
 			}else{
 				int cnt = 0;
 				int mid = (l + r)/2;
 				for(int i = mid + 1; i <= r; i++){
 					for(auto [u,v]:edges[i])dsu.merge(u,v);
 				}
 				dfs(l,mid);
 				for(int i = mid + 1; i <= r; i++){
 					for(auto [u,v]:edges[i])dsu.roll_back();
 				}
 				for(int i = l; i <= mid; i++){
 					for(auto [u,v]:edges[i])dsu.merge(u,v);
 				}
 				dfs(mid + 1,r);
 				for(int i = l; i <= mid; i++){
 					for(auto [u,v]:edges[i])dsu.roll_back();
 				}
 			}
 			
 		};
 		dfs(1,n);
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