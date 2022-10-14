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
#define hell           998244353
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
template<int mod>
struct mint {
  int x;
  mint():x(0){}
  mint(int x):x((x%mod+mod)%mod){}
  // mint(int x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}

  friend istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
  friend ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
  mint<mod> expo(mint<mod> x,int y){
       mint<mod> a=1;
       while(y){
       	 if(y&1)a=a*x;
       	 x=x*x;
       	 y/=2;
       }
       return a;
  }
};
template<int mod>
int operator+=(int& b,mint<mod> a){return b=b+a.x;};
int a[500005];
vector<pair<pii,int>> v;
mint<hell> dp[500005];
mint<hell> pre[500005];
int last[500005];
int solve(){
 int n,k,m;cin>>n>>k>>m;
 v.resize(m);
 rep3(m)cin>>v[i].x>>v[i].y;
 mint<hell> ans=1;
 for(int j=0;j<k;j++){
 	 for(int i=0;i<=n+1;i++)a[i]=0,last[i]=0;
     for(int i=0;i<m;i++){
     	int x=v[i].y;
     	if((x&(1<<j)))a[v[i].x.x]++,a[v[i].x.y+1]--;
        else maxs(last[v[i].x.y+1],v[i].x.x); 
     }
     for(int i=1;i<=n+1;i++)a[i]+=a[i-1];
     for(int i=1;i<=n+1;i++)maxs(last[i],last[i-1]);	
     for(int i=0;i<=n+1;i++)dp[i]=pre[i]=0;
     dp[0]=1;
     pre[0]=1; 
     //for(int i=1;i<=n+1;i++)cout<<a[i]<<" ";cout<<endl;
     for(int i=1;i<=n+1;i++){
     	if(a[i])dp[i]=0;
     	else{
     		dp[i]=dp[i]+pre[i-1];
     		if(last[i]!=0)dp[i]-=pre[last[i]-1];
     	}
     	pre[i]+=(dp[i]+pre[i-1]);
     }
     //for(int i=1;i<=n+1;i++)cout<<dp[i]<<" ";cout<<endl;
     //for(int i=1;i<=n+1;i++)cout<<last[i]<<" ";cout<<endl;	
     //for(int i=1;i<=n+1;i++)cout<<pre[i]<<" ";cout<<endl;	
     ans=ans*dp[n+1];	
 }
 cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef sieve
    sieve();
    #endif
    #ifdef ncr
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}