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

const int N=100005;
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
struct node{
    int a=0;
    int idx=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=max(n1.a,n2.a);
        if(a==n2.a)idx=n2.idx;
        else idx=n1.idx;
    }
};
template<typename node>
struct segtree{
  node t[4*N];
  int tl[4*N];
  int tr[4*N];
  void build(int v,int start,int end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=0;
          t[v].idx=tl[v];
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
  node query(int v,int l,int r){
      if(tr[v]<l || tl[v]>r)return 0;
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
  void upd(int l,int r,int val){
      return zeno(1,l,r,val);
  }   
};
segtree<node> seg;
int dp[100005];
int solve(){
 int n;cin>>n;
 vector<pair<int,pii>>v;
 v.pb({-1e9,{0,0}});
 rep3(n){
 	int x,h;
 	cin>>x>>h;
 	v.pb({x,{h,i+1}});
 }
 sort(all(v));
 dp[n]=1;
 seg.build(1,1,n);
 seg.upd(n,n,1+n);
 int ans[n+1];
 ans[v[n].y.y]=1;
 for(int i=n-1;i>0;i--){
 	int x=v[i].x;
 	int h=v[i].y.x;
 	pair<int,pii> p={x+h-1,{-1,-1}};
 	int r=upper_bound(all(v),p)-v.begin();
 	//cout<<v[i].x<<" "<<r<<endl;
 	if(r>n){
       auto s=seg.query(i,n);
       dp[i]+=s.a-i;
 	}
 	else{
 		if(v[r].x>x+h-1)r--;
 		auto s=seg.query(i,r);
 		if(s.a==0)dp[i]=1;
 		else dp[i]=(s.a-i);
 	}
 	seg.upd(i,i,dp[i]+i);
 	ans[v[i].y.y]=dp[i];
 }
 for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
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