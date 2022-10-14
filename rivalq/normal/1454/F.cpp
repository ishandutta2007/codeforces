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

struct node{
    int a=0;
    int b=0;
    node (int val=0){
        	a=hell;
        	b=-hell;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
        this->b=max(n1.b,n2.b);
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
  void build(int v,int start,int end,int arr[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=arr[start];
          t[v].b=arr[start];
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
      if(tr[v]<l || tl[v]>r)return nul;
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
int a[N];

int solve(){
 	int n;cin>>n;
 	map<int,vector<int>>mp;
 	rep(i,1,n+1){
 		cin>>a[i];
 		mp[a[i]].pb(i);
 	}
 	int mx=0;
 	seg.build(1,1,n,a);
 	rep(i,1,n-1){
 		maxs(mx,a[i]);
 		if(mp[mx].back()<=i)continue;
 		int j=upper_bound(all(mp[mx]),i)-mp[mx].begin();
 		j=mp[mx][j];
 		auto s=seg.query(i+1,j);
 		if(s.a<mx)continue;
 		int L=j,R=n-1;
 		int l1=L+1,r1=L+1;
 		while(L<=R){
 			int M=(L+R)/2;
 			auto s=seg.query(i+1,M);
 			if(s.a==mx){
 				L=M+1;
 				r1=M+1;
 			}
 			else{
 				R=M-1;
 			}
 		}
 		j = mp[mx].back();
 		auto t=seg.query(j,n);
 		if(t.b>mx)continue;
 		L=i+1,R=j;
 		int l2=j,r2=j;
 		while(L<=R){
 			int M=(L+R)/2;
 			auto s=seg.query(M,n);
 			if(s.b==mx){
 				R=M-1;
 				l2=M;
 			}
 			else{
 				L=M+1;
 			}
 		}
 		if(max(l2,l1)<=min(r1,r2)){
 			int rx=min(r1,r2);
 			int z=n-rx+1;
 			int y=n-z-i;
 			cout<<"YES"<<endl;
 			cout<<i<<" "<<y<<" "<<z<<endl;return 0;
 		}
 	}
 	cout<<"NO"<<endl;
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