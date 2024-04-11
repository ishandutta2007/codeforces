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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
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
};

mint<998244353> dp[3001][3001];
int solve(){
 string s,t;cin>>s>>t;
 int n=s.length();
 int m=t.length();
 for(int i=m-1;i<n;i++){
 	if(i>=m || s[i]==t[m-1])dp[i][0]+=1;
 	if(s[i]==t[0])dp[i][1]+=1;
 }
 for(int i=n-1;i>=0;i--){
 	for(int j=0;j<=(n-i);j++){
 	  if(j>0){	
 		if(j>m || s[i]==t[j-1]){
 			dp[i][j]+=dp[i+1][j-1];
 		}
 	  }
 	  int r=j+i+1;
 	  if(r>m  || s[i]==t[r-1])dp[i][j]+=dp[i+1][j];
 	}
 }
 mint<998244353> sum=0;
 for(int i=0;i<=n;i++)sum+=dp[0][i];
 cout<<sum<<endl;
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