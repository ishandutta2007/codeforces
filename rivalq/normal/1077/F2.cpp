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
 int n,k,x;cin>>n>>k>>x;
 int a[n+1];
 rep3(n)cin>>a[i+1];
 int req=n/k;
 if(req>x){
 	cout<<-1<<endl;exit(0);
 }
 vector<vector<int>>dp(n+1,vector<int>(x+1,-1e18));
 dp[1][1]=a[1];
 deque<int>st[x+1];
 st[1].push_back(1); 
 for(int i=2;i<=n;i++){
 	if(i<=k){
 		dp[i][1]=a[i];
 	}
 	for(int j=1;j<x;j++){
 		while(!st[j].empty() && st[j].front()<i-k)st[j].pop_front();
 	}
 	for(int j=2;j<=x;j++){
 		if(j<ceil(1.0*i/k) || j>i){
 			continue;
 		}
 		if(st[j-1].empty())continue;
 		dp[i][j]=dp[st[j-1].front()][j-1]+a[i];
 	}
 	for(int j=1;j<x;j++){
 		if(dp[i][j]<=0)continue;
 		while(!st[j].empty() && dp[st[j].back()][j]<=dp[i][j])st[j].pop_back();
 		st[j].push_back(i);
 	} 
 }
 int ma=0;
 for(int i=n-k+1;i<=n;i++)maxs(ma,dp[i][x]);
 cout<<ma<<endl;	
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