#include<bits/stdc++.h>
#pragma GCC "optimize"(O3)
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
struct node{
    int a=0;
    node (int val=0){
        a=val;
    }
    void merge(node &n1,node &n2){
        this->a=min(n1.a,n2.a);
    }
}nul;
const int N=5005;
template<typename node>
struct segtree{
  node t[4*N];
  int32_t tl[4*N];
  int32_t tr[4*N];
  void build(int32_t v,int32_t start,int32_t end){
      tl[v]=start;
      tr[v]=end;
      if(start==end){
          t[v].a=1e18;
      }
      else{
          int m=(start+end)/2;
          build(2*v,start,m);
          build(2*v+1,m+1,end);
          t[v].merge(t[2*v],t[2*v+1]);
     }
  }
  void zeno(int32_t v,int32_t l,int32_t r,int val){
      if(tr[v]<l || tl[v]>r)return;
      if(l<=tl[v] && tr[v]<=r){
            t[v].a=val;
            return;
      }
      zeno(2*v,l,r,val);
      zeno(2*v+1,l,r,val);
      t[v].merge(t[2*v],t[2*v+1]);
  }
  node query(int32_t v,int32_t l,int32_t r){
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
  node query(int32_t l,int32_t r){
      return query(1,l,r);
  }
  void upd(int32_t l,int32_t r,int val){
      return zeno(1,l,r,val);
  }   
};
segtree<node>seg;
int dp[5001][5001];
int temp1[5001];
int temp2[5001];
int solve(){
 int32_t n,m;cin>>n>>m;
 vector<int>v(n+1);
 v[0]=-1e10;;
 rep(i,1,n+1)cin>>v[i];
 sort(all(v));
 vector<pii>v2(m+1);
 v2[0]={-1e10,-1e10};
 rep(i,1,m+1)cin>>v2[i];
 sort(all(v2));
 seg.build(1,0,n);
 seg.upd(0,0,0);
 for(int i=1;i<=n;i++){
    temp1[i]=temp1[i-1]+abs(v2[1].x-v[i]);
    if(i<=v2[1].y)dp[1][i]=temp1[i];
 }
 for(int i=v2[1].y+1;i<=n;i++)dp[1][i]=1e18;

 if(m==1){
    if(n<=v2[1].y)cout<<dp[1][n]<<endl;
    else cout<<-1<<endl;
    return 0;
 }
 int temp3[n+1];
 for(int i=0;i<=n;i++)temp3[i]=1e18;
 temp3[0]=0;
 for(int i=1;i<=n;i++){
 	temp2[i]=temp2[i-1]+abs(v2[2].x-v[i]);
    temp3[i]=dp[1][i]-temp2[i]; 
 }
 for(int i=2;i<=m;i++){
 	for(int j=1;j<=n;j++){
 		temp1[j]=temp1[j-1]+abs(v2[i].x-v[j]);
 		if(i<m)temp2[j]=temp2[j-1]+abs(v2[i+1].x-v[j]);
 	}
 	deque<int>dq;
 	dp[i][0]=0;
 	int mi=temp3[0];
 	dq.push_back(0);
 	for(int j=1;j<=v2[i].y;j++){
 		mi=mins(mi,temp3[j]);
 		dp[i][j]=mi+temp1[j];
 		while(!dq.empty() && temp3[j]<=temp3[dq.back()])dq.pop_back();
 		dq.push_back(j);
 	}
    for(int j=v2[i].y+1;j<=n;j++){
    	while(!dq.empty() && temp3[j]<=temp3[dq.back()])dq.pop_back();
    	while(!dq.empty() && j-dq.front()>v2[i].y)dq.pop_front();
    	dq.push_back(j);
    	dp[i][j]=temp1[j]+temp3[dq.front()];
    }
 	for(int j=1;j<=n;j++){
 		temp3[j]=dp[i][j]-temp2[j];
 	}

 }
 if(dp[m][n]>=1e18)cout<<-1<<endl;
 else  cout<<dp[m][n]<<endl;	
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    nul.a=1e18;
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