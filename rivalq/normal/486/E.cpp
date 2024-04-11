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


const int N=1e5+5;

struct node{
    int a=0;
    int b=0;
    int c=0;
    node (int val=0){
        a=val;b=-1,c=-1;
    }
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
        if(n1.a==n2.a)b=min(n1.b,n2.b);
        else if(n1.a==a)b=n1.b;
        else b=n2.b;
       	if(n1.a==n2.a)c=max(n1.c,n2.c);
        else if(n1.a==a)c=n1.c;
        else c=n2.c;
    }
};
struct update{
  int val=0;
  int i;
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
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=0;
          t[v].b=-1;
          t[v].c=-1;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,update val){
      pushdown(v);
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            if(t[v].a<val.val){
            		t[v].a=val.val;
            		t[v].b=t[v].c=val.i;
            }
            else if(t[v].a==val.val){
            		mins(t[v].b,val.i);
            		maxs(t[v].c,val.i);
            }
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
 	int n;cin>>n;
 	vector<int>a(n+1);
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	vector<pii>dp1(n+1),dp2(n+1);
 	seg.build(1,1,N-1);
 	set<int>s1,s2;
 	pii p1={0,0},p2={0,0};
 	rep(i,1,n+1){
 			auto s = seg.query(1,a[i]-1);
 			dp1[i].x = 1+s.a;
 			dp1[i].y = s.b;
 			update upd;upd.val=dp1[i].x+1;
 			upd.i=i;
 			seg.upd(a[i],a[i],upd);
 			if(p1.x<dp1[i].x){
 				p1.x=dp1[i].x;
 				p1.y=i;
 			}
 	}
 	seg.build(1,1,N-1);
 	for(int i=n;i>=1;i--){
 			auto s = seg.query(a[i]+1,1e5);
 			dp2[i].x = 1+s.a;
 			dp2[i].y = s.c;
 			update upd;upd.val=dp2[i].x+1;
 			upd.i=i;
 			seg.upd(a[i],a[i],upd);
 			maxs(p2,make_pair(dp2[i].x,i));
 	}
 	int res = p1.x;
 	while(1){
 		if(p1.y<=0)break;
 		s1.insert(p1.y);
 		p1.y=dp1[p1.y].y;
 	}
 	while(1){
 		if(p2.y<=0)break;
 		s2.insert(p2.y);
 		p2.y=dp2[p2.y].y;
 	}
 	string ans(n,'1');
 	rep(i,1,n+1){
 		if(s1.count(i) && s2.count(i))ans[i-1]='3';
 		else if(dp1[i].x+dp2[i].x-1==res)ans[i-1]='2';
 		else ans[i-1]='1';
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