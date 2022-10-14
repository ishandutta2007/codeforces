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
const int maxn=200005;
vector<int> g[maxn];
int p[maxn];
int b_p[maxn][21];
int level[maxn];
int tin[maxn],tout[maxn];
int eu[maxn];
int val[maxn];
int t=0;
void dfs(int n,int e,int l){
     p[n]=e;
     level[n]=l;
     tin[n]=++t;
     eu[t]=n;
     for(auto i:g[n]){
         if(i!=e){
             dfs(i,n,l+1);
         }
     }
     tout[n]=t;
     return;
}
void lift(int n){
     for(int i=0;i<=20;i++){
         for(int j=1;j<=n;j++){
             if(i==0)b_p[j][i]=p[j];
             else b_p[j][i]=b_p[b_p[j][i-1]][i-1];
         }
     }
     return;
}
int lca(int u, int v){
   if(level[v]<level[u])u=v+u-(v=u);
   int diff=level[u]-level[v];
   for (int i=20;i >= 0; i--) {
        if (level[v]-level[u] >=(1 << i)) {
            v = b_p[v][i];
        }
   }
   if(v==u){
       return u;
   }
   int k=ceil(log2(level[u]));
   while(k>=0){
        if(b_p[u][k]!=b_p[v][k]){
            u=b_p[u][k];
            v=b_p[v][k];
        }
        k--;
   } 
   return p[u];

}
const int N=maxn;
struct node{
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=n1.a+n2.a;
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val+=par.val;
  }
  void apply(node &node,int tl,int tr){
      node.a+=val*(tr-tl+1);
      val=0;
  }
};
template<typename node,typename update>
struct segtree{
  node t[4*N];
  bool lazy[4*N];
  update zaker[4*N];
  int tl[4*N];
  int tr[4*N];
  node nul;
  inline void pushdown(int v){
     if(lazy[v]){    
       apply(zaker[v],v);
       lazy[v]=0;
       zaker[v].apply(t[v],tl[v],tr[v]);
     }
  }
  inline void apply(update &u,int v){
      if(tl[v]!=tr[v]){
          lazy[2*v]=lazy[2*v+1]=1;
          zaker[2*v].combine(u,tl[2*v],tr[2*v]);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1]);
      }
  }
  void build(int v,int start,int end,int arr[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=val[arr[start]];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr);
          build(2*v+1,m+1,end,arr);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a+=val.val*(tr[v]-tl[v]+1);
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return nul;
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return t[v];
      }
      node a=query(2*v,l,r);
      node b=query(2*v+1,l,r);
      node ans;
      ans.merge(a,b);
      return ans;
  }
public:
  node query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};
segtree<node,update> seg;
int solve(){
 	int n,q;cin>>n>>q;
 	int root=1;
 	rep(i,1,n+1)cin>>val[i];
 	rep3(n-1){
 		int a,b;cin>>a>>b;
 		g[a].pb(b);
 		g[b].pb(a);
 	}
 	dfs(1,1,0);
 	lift(n);
 	seg.build(1,1,n,eu);
 	update upd;
 	auto get=[&](int u,int k){
             if(k==0)return u;
             for(int i=20;i>=0;i--){
             	  if(k&(1<<i)){
             	  	u=b_p[u][i];
             	  }
             }
             return u;
 	};
 	auto f=[&](int root,int u,int x){
 		int k=level[root]-level[u]-1;
                int kth=get(root,k);
                update upd;upd.val=x;
                seg.upd(1,n,upd);upd.val=-x;
                seg.upd(tin[kth],tout[kth],upd); 
 	};
 	rep3(q){
 		int t;cin>>t;
 		int u;cin>>u;
 		if(t==1){
 			root=u;
 		}
 		else if(t==2){
 			int v;cin>>v;
 			int x;cin>>x;
 			upd.val=x;
 			int n1=lca(u,v);
                        int n2=lca(v,root);
                        int n3=lca(u,root);
                        if(level[n2]>level[n1])swap(n2,n1);
                        if(level[n3]>level[n1])swap(n3,n1);
                        if(n1==root){
                        	seg.upd(1,n,upd);
                        }
                        else if((tin[n1]<=tin[root] && tin[root]<=tout[n1])){
                                f(root,n1,x); 
                        }
                        else{ 
                        	seg.upd(tin[n1],tout[n1],upd);
                        }
 		}
 		else{
 			if(root==u){
 				cout<<seg.t[1].a<<endl;
 			}
 			else if(tin[u]<=tin[root] && tout[u]>=tin[root]){
 				int k=level[root]-level[u]-1;
                                int kth=get(root,k);
                                //cout<<kth<<" "<<i+1<<endl;
 				cout<<seg.t[1].a-seg.query(tin[kth],tout[kth]).a<<endl;
 			}
 			else{
 				cout<<seg.query(tin[u],tout[u]).a<<endl;
 			}
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