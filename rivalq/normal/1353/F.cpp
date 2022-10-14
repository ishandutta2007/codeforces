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
int dp[101][101];
int a[101][101];
int func(int k,int n,int m){
    dp[1][1]=abs(k-a[1][1]); 
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(i==1 && j==1) continue;
    		dp[i][j]=1e18;
    		if(i>1)dp[i][j]=min(dp[i][j],abs(k-a[i][j])+dp[i-1][j]);
    		if(j>1)dp[i][j]=min(dp[i][j],abs(k-a[i][j])+dp[i][j-1]);

    	}
    }
    return dp[n][m];
}
int solve(){
 int n,m;cin>>n>>m;
 vector<pair<int,pii>>vec;
 rep(i,1,n+1){
 	rep(j,1,m+1){
 		cin>>a[i][j];
 		a[i][j]=a[i][j]-i-j+2;
 		pii p={i,j};
 		vec.pb({a[i][j],p});
 	}
 }
 sort(all(vec));
 int mi=1e18;
 for(auto i:vec){
 	mins(mi,func(i.x,n,m));
 	a[i.y.x][i.y.y]=1e18;
 }
 cout<<mi<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}