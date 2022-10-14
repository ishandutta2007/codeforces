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

const int N=2e5+5;

auto eval=[](pii p){
	return p.x*p.y;
};

struct node{
    int wait=0;
    pii p;
    void merge(node &n1,node &n2){
         	this->wait=min(n1.wait,n2.wait);
         	pii p1=n1.p;
         	pii p2=n2.p;
         	if(eval(p1)<eval(p2))swap(p1,p2);
         	p=p1;
         	if(p2.y>p1.y){
         		// means at some point p2 can overtake;
         		mins(this->wait,(eval(p1)-eval(p2))/(p2.y-p1.y));
         	}
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
  void apply(node &node){
      node.p.x+=val;
      node.wait-=val;
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
       zaker[v].apply(t[v]);
     }
  }
  inline void apply(update &u,int v){
      if(tl[v]!=tr[v]){
          lazy[2*v]=lazy[2*v+1]=1;
          zaker[2*v].combine(u,tl[2*v],tr[2*v]);
          zaker[2*v+1].combine(u,tl[2*v+1],tr[2*v+1]);
      }
  }
  void build(int v,int start,int end,vector<pii>&arr){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].p=arr[start];
          t[v].wait=1e18;
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
      // max of this node will not change
      // hence we can safily decrease its potential
      if(l<=tl[v] && tr[v]<=r && t[v].wait>=val.val){
            t[v].p.x+=val.val;
            t[v].wait-=val.val;
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      // pull the values from child
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return 0;
      pushdown(v);
      if(l<=tl[v] && tr[v]<=r){
         return eval(t[v].p);
      }
      int a=query(2*v,l,r);
      int b=query(2*v+1,l,r);
      return max(a,b);
  }
public:
  int query(int l,int r){
      return query(1,l,r);
  }
  void upd(int l,int r,update val){
      return zeno(1,l,r,val);
  }   
};


segtree<node,update>seg1,seg2;

vector<int>g[N];


int solve(){
 	int n,m;cin>>n>>m;
 	rep(i,2,n+1){
 		int p;cin>>p;
 		g[p].pb(i);
 	}
 	vector<int>a(n+1),b(n+1);
 	vector<int>eu(n+1),in(n+1),out(n+1);
 	vector<pii>vec(n+1);
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	rep(i,1,n+1){
 		cin>>b[i];
 	}
 	int t=0;
 	function<void(int,int)>dfs=[&](int u,int p){
 		in[u]=++t;
 		eu[t]=u;
 		for(auto i:g[u]){
 			a[i]+=a[u];
 			b[i]+=b[u];
 			dfs(i,u);
 			
 		}
 		out[u]=t;
 	};dfs(1,1);
 	rep(i,1,n+1){
 		vec[i].x=a[eu[i]];
 		vec[i].y=b[eu[i]];
 	}
 	seg1.build(1,1,n,vec);
 	rep(i,1,n+1){
 		vec[i].y*=-1;
 	}
 	seg2.build(1,1,n,vec);
 	rep(i,0,m){
 		int t;cin>>t;
 		if(t==1){
 			int v,x;cin>>v>>x;
 			seg1.upd(in[v],out[v],x);
 			seg2.upd(in[v],out[v],x);
 		}
 		else{
 			int v;cin>>v;
 			cout<<max(seg1.query(in[v],out[v]),seg2.query(in[v],out[v]))<<endl;
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