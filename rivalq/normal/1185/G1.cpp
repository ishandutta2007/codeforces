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
mint<hell>dp[51][51][51][4];
mint<hell>fact[100];
mint<hell>dpa[51][2501];
mint<hell>dpb[51][51][2501];
int solve(){
 int n,t;cin>>n>>t;
 vector<pii>a(n);
 rep3(n)cin>>a[i];
 dp[1][0][0][1]=1;
 dp[0][1][0][2]=1;
 dp[0][0][1][3]=1;
 for(int i=0;i<=50;i++){
 	for(int j=0;j<=50;j++){
 		for(int k=0;k<=50;k++){
 			if(i+j+k<=1)continue;
 			for(int t=1;t<=3;t++){
 				if(t==1){
 					if(i>0)dp[i][j][k][1]=dp[i-1][j][k][2]+dp[i-1][j][k][3];
 				}
 				else if(t==2){
 					if(j>0)dp[i][j][k][2]=dp[i][j-1][k][1]+dp[i][j-1][k][3];
 				}
 				else {
 					if(k>0)dp[i][j][k][3]=dp[i][j][k-1][1]+dp[i][j][k-1][2];
 				}
 			}
 		}
 	}
 }
 dpa[0][0]=1;
 dpb[0][0][0]=1;
 int cnt1=0,cnt2=0,cnt3=0;
 for(int i=0;i<n;i++){
 	if(a[i].y==1){
 		for(int j=cnt1;j>=0;j--){
 			for(int t=0;t<=2500;t++)dpa[j+1][t+a[i].x]+=dpa[j][t];
 		}
 	    cnt1++;
    }
 	else{
 		for(int j=cnt2;j>=0;j--){
           for(int k=cnt3;k>=0;k--){
           	   for(int t=0;t<=2500;t++){
           	   	  if(a[i].y==2)dpb[j+1][k][t+a[i].x]+=dpb[j][k][t];
           	   	  if(a[i].y==3)dpb[j][k+1][t+a[i].x]+=dpb[j][k][t]; 
           	   }
           }
 		}
 		if(a[i].y==2)cnt2++;
 		if(a[i].y==3)cnt3++;
 	}
 }
 mint<hell>ans=0;
 for(int i=0;i<=t;i++){
    for(int t1=0;t1<=cnt1;t1++){
       for(int t2=0;t2<=cnt2;t2++){
       	 for(int t3=0;t3<=cnt3;t3++){
       	 	mint<hell>ways=dpa[t1][i]*dpb[t2][t3][t-i];
       	 	mint<hell>ways2=dp[t1][t2][t3][1]+dp[t1][t2][t3][2]+dp[t1][t2][t3][3];
       	 	ways2=ways2*fact[t1]*fact[t2]*fact[t3];
       	 	ans+=ways*ways2;
       	 }
       }
    }
 }
 cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fact[0]=1;
    for(int i=1;i<100;i++){
    	mint<hell>val=i;
    	fact[i]=val*fact[i-1];
    }
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