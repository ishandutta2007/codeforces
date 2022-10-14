#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order
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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
const int N=200005;
struct node{
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
    }
};
template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
  node nul;
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=0;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int v,int l,int r,int val){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a=val;
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  int query(int v,int l,int r,int val){
      if(tl[v]>r || l>tr[v])return -1;
      if(tl[v]>=l && tr[v]<=r){
      	 if(t[v].a<=val)return -1;
      	 while(tl[v]!=tr[v]){
      	 	int val1=t[2*v].a;
      	 	int val2=t[2*v+1].a;
      	 	if(val1>val){
      	 		v=2*v;
      	 	}
      	 	else{
      	 		v=2*v+1;
      	 	}
      	 }
      	 return tl[v];
      }
      int a=query(2*v,l,r,val);
      if(a!=-1)return a;
      return query(2*v+1,l,r,val); 
  }
public:
  int query(int l,int r,int val){
      return query(1,l,r,val);
  }
  void upd(int l,int r,int val){
      return zeno(1,l,r,val);
  }   
};
segtree<node>seg;
set<int>s[N];
int solve(){
 int n;cin>>n;
 Tree<int>x;
 vector<pair<int,pii>>q(n+1);
 seg.build(1,1,n);
 for(int i=1;i<=n;i++){
   string s;cin>>s;
   cin>>q[i].y;
   x.insert(q[i].y.x);
   if(s=="add")q[i].x=1;
   else if(s=="remove")q[i].x=2;
   else q[i].x=3;
 }
  for(int i=1;i<=n;i++){
 	if(q[i].x==3){
 		int xx=x.ook(q[i].y.x)+1;
 		int y=q[i].y.y;
 		int a=seg.query(xx+1,n,y);
 		if(a==-1)cout<<a<<endl;
 		else cout<<*x.fbo(a-1)<<" "<<*s[a].upper_bound(y)<<endl;
 	}
 	else if(q[i].x==1){
 		int xx=x.ook(q[i].y.x)+1;
 		int y=q[i].y.y;
 		s[xx].insert(y);
 		seg.upd(xx,xx,*s[xx].rbegin());
 	}
 	else{
 		int xx=x.ook(q[i].y.x)+1;
 		int y=q[i].y.y;
 		s[xx].erase(y);
 		int val=-1;
 		if(!s[xx].empty())val=*s[xx].rbegin();
 		seg.upd(xx,xx,val);
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