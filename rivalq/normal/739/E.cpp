#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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

#define ld double

const int N=3000;
const ld eps=1e-8;
const int inf=1e9;

ld dp[N][N];
int cnt[N][N];
ld p1[N],p2[N];
int solve(){
 		int n,a,b;cin>>n>>a>>b;
 		rep(i,1,n+1){
 			cin>>p1[i];
 		}
 		rep(i,1,n+1){
 			cin>>p2[i];
 		}
 		
 		auto calc=[&](ld x){
 			for(int i=0;i<=n;i++)dp[0][i]=-inf;
 			dp[0][0]=0;
 			cnt[0][0]=0;
 			for(int i=1;i<=n;i++){
 				for(int j=0;j<=a;j++){
 					dp[i][j]=dp[i-1][j];
 					cnt[i][j]=cnt[i-1][j];
 					if(dp[i-1][j]+p2[i]-x>dp[i][j]){
 						dp[i][j]=dp[i-1][j]+p2[i]-x;
 						cnt[i][j]=cnt[i-1][j]+1;
 					}
 					if(abs(dp[i-1][j]+p2[i]-x-dp[i][j])<eps){
 						if(cnt[i][j]<cnt[i-1][j]+1)cnt[i][j]=cnt[i-1][j]+1;
 					}
 					if(j>0){
 						if(dp[i-1][j-1]+p1[i]>dp[i][j]){
 							dp[i][j]=dp[i-1][j-1]+p1[i];
 							cnt[i][j]=cnt[i-1][j-1];
 						}
 						if(abs(dp[i-1][j-1]+p1[i]-dp[i][j])<eps){
 							if(cnt[i][j]<cnt[i-1][j-1])cnt[i][j]=cnt[i-1][j-1];
 						}
 						if(dp[i][j]<dp[i-1][j-1]+p1[i]+p2[i]-p1[i]*p2[i]-x){
 								dp[i][j]=dp[i-1][j-1]+p1[i]+p2[i]-p1[i]*p2[i]-x;
 								cnt[i][j]=cnt[i-1][j-1]+1;
 						}
 						if(abs(dp[i-1][j-1]+p1[i]+p2[i]-p1[i]*p2[i]-x-dp[i][j])<eps){
 							    if(cnt[i][j]<cnt[i-1][j-1]+1)cnt[i][j]=cnt[i-1][j-1]+1;
 						}
 					}
 				}
 			}
 			return make_pair(cnt[n][a],dp[n][a]);	
 		};
 		ld l=0,r=1;
 		ld ans=-1;
 		for(int i=0;i<50;i++){
 			ld mid=(l+r)/2;
 			auto s=calc(mid);
 			if(s.x>=b){
 				ans=s.y+mid*b;
 				l=mid;
 			}
 			else{
 				r=mid;
 			}
 		}
 		cout<<fixed<<setprecision(10)<<ans<<endl;
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