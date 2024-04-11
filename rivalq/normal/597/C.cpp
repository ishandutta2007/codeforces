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
const int N=100005;
struct node{
    int a[12]={0};
    node (int val=0){}
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
      mem0(t[v].a);
      if(start==end){
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
       }
  }
  void zeno(int v,int l,int r,int val,int f){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a[f]+=val;
            return;
      }
      zeno(2*v,l,r,val,f);
      zeno(2*v+1,l,r,val,f);
      t[v].a[f]=t[2*v].a[f]+t[2*v+1].a[f];
  }
  int query(int v,int l,int r,int f){
      if(tr[v]<l || tl[v]>r)return 0;
      if(l<=tl[v] && tr[v]<=r){
         return t[v].a[f];
      }
      int a=query(2*v,l,r,f);
      int b=query(2*v+1,l,r,f);
      return a+b;
  }
public:
  int query(int l,int r,int f){
      return query(1,l,r,f);
  }
  void upd(int l,int r,int val,int f){
      return zeno(1,l,r,val,f);
  }   
};
segtree<node>seg;
int dp[100005][12];
int solve(){
 int n,k;cin>>n>>k;
 k++;
 seg.build(1,1,n);
 for(int i=1;i<=n;i++){
 	 int t;cin>>t;
   dp[i][1]++;
   seg.upd(t,t,1,1);
   for(int j=2;j<=k;j++){
      dp[i][j]=seg.query(1,1,t-1,j-1);
      seg.upd(t,t,dp[i][j],j);
   } 
 }
 cout<<seg.query(1,n,k)<<endl;
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