#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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

const int N=1e5+5;
const int M=6e5+10;
vector<int>ask[M];
vector<int>ans;
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
       	    rank[px]+=rank[py];
       	    rank[py]=0;
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
struct query{
      int v,u;
      bool united;	
      query(){}
      query(int u,int v):u(u),v(v){}
};
struct Query_Tree{
      vector<vector<query>>t;
      dsu_with_rollbacks dsu;
      int T;
      Query_Tree(){}
      Query_Tree(int __T,int __n):T(__T+1){
           dsu=dsu_with_rollbacks(__n);
           t.resize(4*T+10);
      }   
      void add(int v,int tl,int tr,int l,int r,query& q){
      	   if(tl>r || l>tr)return;
      	   if(l<=tl && tr<=r){
      	   	t[v].pb(q);return;
      	   }
      	   int mid=(tl+tr)/2;
      	   add(2*v,tl,mid,l,r,q);
      	   add(2*v+1,mid+1,tr,l,r,q);
      }
      void add(int l,int r,query& q){
      	   add(1,1,T,l,r,q);
      }
      void dfs(int v,int tl,int tr){
           for(query&q:t[v]){
           	q.united=dsu.merge(q.v,q.u);
           	//cout<<tl<<" "<<q.united<<" "<<q.v<<" "<<q.u<<endl;
           }
           if(tl==tr){
           		for(auto j:ask[tl]){
           			ans[tl]=dsu.rank[dsu.root(j)];
           		}
           }
           else{
           	int mid=(tl+tr)/2;
           	dfs(2*v,tl,mid);
           	dfs(2*v+1,mid+1,tr);
           } 
           for(query&q:t[v]){
               if(q.united){
               	  dsu.roll_back();
               }
           }
      }
      void dfs(){
      	   dfs(1,1,T); 
      }
}qt;


vector<pair<int,pii>>edges[M];

int solve(){
 	int n,q,k;cin>>n>>q>>k;
 	int j=1;
 	qt= Query_Tree(q,n+1);
 	ans.resize(q+1,-1);
 	rep(i,1,q+1){
 		int t;cin>>t;
 		if(t==1){
 			int x,y;cin>>x>>y;
 			edges[min(q,j+k-1)].pb({i,{x,y}});
 		}
 		else if(t==2){
 			int z;cin>>z;
 			ask[i].pb({z});
 		}
 		else{
 			for(auto k:edges[j]){
 				int l=k.x;
 				int r=i;
 				query qq={k.y.x,k.y.y};
 				qt.add(l,r,qq);
 			}
 			edges[j].clear();
 			j++;
 		}
 	}
 	for(j;j<=q;j++){
 		 for(auto k:edges[j]){
 		 	int l=k.x;
 			int r=q;
 			query qq={k.y.x,k.y.y};
 			qt.add(l,r,qq);
 		 }
 	}
 	qt.dfs();
 	rep(i,1,q+1){
 		if(ans[i]==-1)continue;
 		cout<<ans[i]<<endl;
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