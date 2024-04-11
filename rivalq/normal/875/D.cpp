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

int last[30];

struct node{
    int a=0;
    int b=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
        if(a==n1.a)b=n1.b;
        else b=n2.b;
    }
};
struct update{
  int val=0;
  update(int t=0){
     val=t;
  }
  void combine(update &par,int tl,int tr){
      val=par.val;
  }
  void apply(node &node){
      node.a=val;
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
  void build(int v,int start,int end,vector<int>&arr){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=arr[start];
          t[v].b=tl[v];
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
            t[v].a=val.val;
            apply(val,v); 
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return node(-1e9);
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
segtree<node,update>seg;

int solve(){
 	int n;cin>>n;
 	vector<int>a(n+1);
 	vector<int>v(n+1,0),k(n+1,n+1);
 	vector<int>pre(n+1);
 	rep(i,0,30){
 		last[i]=0;
 	}
 	rep(i,1,n+1){
 		cin>>a[i];
 		for(int j=29;j>=0;j--){
 			if(a[i]&(1<<j)){
 				last[j]=i;
 			}
 			else{
 				maxs(v[i],last[j]);
 			}
 		}
 	}
 	seg.build(1,1,n,a);
 	rep(i,0,30){
 		last[i]=n+1;
 	}
 	for(int i=n;i>=1;i--){
 		for(int j=29;j>=0;j--){
 			if(a[i]&(1<<j)){
 				last[j]=i;
 			}
 			else{
 				mins(k[i],last[j]);
 			}
 		}
 	}
 	
 	int ans=0;
 	function<void(int,int)>dfs=[&](int l,int r){
 		if(l>=r)return;
 		auto s=seg.query(l,r);
 		int i=s.b;
 		int l1=r-i,l2=i-l;
 		int tot=l1*l2+l1+l2+1;
 		maxs(v[i],l-1);
 		mins(k[i],r+1);
 		l1=k[i]-i-1;
 		l2=i-v[i]-1;
 		tot-=1+l1*l2+l1+l2;
 		ans+=tot;
 		dfs(l,i-1);
 		dfs(i+1,r);	
 	};
 	dfs(1,n);
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