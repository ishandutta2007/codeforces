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
struct node{
    Tree<pii>tr;
    node (int val=0){
    }
    void merge(node &n1,node &n2){
        for(auto i:n1.tr)tr.insert(i);
        for(auto i:n2.tr)tr.insert(i);
    }
    int query(int k){
    	return  sz(tr)-tr.ook({k,-1});
    }
};
const int N=2e5+5;
template<typename node>
struct segtree{
  node t[4*N]; 
  int tl[4*N];
  int tr[4*N];
  node nul;
  void build(int v,int start,int end,int arr[]){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].tr.insert({arr[tl[v]],tl[v]});
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m,arr);
          build(2*v+1,m+1,end,arr);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  int query(int v,int l,int r,int k){
      if(tr[v]<l || tl[v]>r)return 0;
      if(l<=tl[v] && tr[v]<=r){
         return t[v].query(k);
      }
      int a=query(2*v,l,r,k);
      int b=query(2*v+1,l,r,k);
      return a+b;
  }
public:
  int query(int l,int r,int k){
      return query(1,l,r,k);
  }
};
segtree<node>seg;
int a[N];
int solve(){
 int n;cin>>n;
 rep(i,1,n+1)cin>>a[i];
 seg.build(1,1,n,a);
 int ans=0;
 for(int i=2;i<=n;i++){
     int r=min(a[i],i-1);
     ans+=seg.query(1,r,i);
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