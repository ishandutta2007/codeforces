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

const int N=3e5+5;

struct node{
    int a=0;
    int b=0;
    int c=0;
    int i=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
        this->b=max(n1.b,n2.b);
        this->c=max(n1.c,n2.c);
        if(n1.c==c)i=n1.i;
        else i=n2.i;
    }
}nul;
template<typename node>
struct segtree{
  node t[4*N];
  bool lazy[4*N];
  int tl[4*N];
  int tr[4*N];
  void build(int v,int start,int end,vector<int>&arr,int c[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=arr[start];
          t[v].b=t[v].a;
          t[v].c=c[start];
          t[v].i=tl[v];
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr,c);
          build(2*v+1,m+1,end,arr,c);
          t[v].merge(t[2*v],t[2*v+1]);
     }
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
};
segtree<node>seg;

int c[N];

int solve(){
 	int n,a;cin>>n>>a;
 	vector<int>p(n+1);
 	vector<int>d(n+1);
 	int mx=0;
 	rep(i,1,n+1){
 		cin>>d[i];
 		int c;cin>>c;
 		p[i]+=p[i-1]+a-c;
 		maxs(mx,a-c);
 	}
 	for(int i=1;i<n;i++)c[i]=(d[i+1]-d[i])*(d[i+1]-d[i]);
 	seg.build(1,0,n,p,c);
 	function<void(int,int)>func=[&](int l,int r){
 		if(l>=r)return;
 		auto s1=seg.query(l,r-1);
 		int i=s1.i;int j=i+1;
 		auto s2=seg.query(j,r);
 		auto s3=seg.query(l-1,i);
 		maxs(mx,s2.b-s3.a-s1.c);
 		func(l,i);
 		func(j,r);
 	};
 	func(1,n);
 	cout<<mx<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    nul.a=9e18;
    nul.b=-9e18;
    nul.c=-9e18;
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