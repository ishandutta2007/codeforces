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


int solve(){
 	int n,k;cin>>n>>k;
 	vector<int>a(n+1,0),b(n+1,0);
 	int s=0;
 	rep(i,1,n+1)cin>>a[i]>>b[i],s+=a[i]+b[i];
 	vector<vector<int>>dp(n+1,vector<int>(k+1,0));
 	dp[0][0]=1;
 	for(int i=1;i<=n;i++){
 		for(int j=0;j<k;j++){
 			dp[i][j]=dp[i-1][(j-a[i]%k+k)%k];
 			for(int l=0;l<=min(a[i],k-1);l++){
                               if((a[i]-l)%k+b[i]>=k){
                               	   dp[i][j]|=dp[i-1][(j-l+k)%k];
                               	   if(dp[i][j]==1)break;
                               }
 			}
 		}
 	}
 	int mx=0;
 	for(int i=0;i<k;i++){
 		if(dp[n][i]){
 			maxs(mx,(s-i)/k);
 		}
 	}
 	cout<<mx<<endl;
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