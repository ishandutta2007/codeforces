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

int dp[201][201][201];

int solve(){
 	int r,g,b;cin>>r>>g>>b;
 	vector<int>v1,v2,v3;
 	rep3(r){
 		int t;cin>>t;
 		v1.pb(t);
 	}
 	rep3(g){
 		int t;cin>>t;
 		v2.pb(t);
 	}
 	rep3(b){
 		int t;cin>>t;
 		v3.pb(t);
 	}
 	sort(all(v1));sort(all(v2));sort(all(v3));
 	reverse(all(v1));reverse(all(v2));reverse(all(v3));
 	int a=0;
 	for(int i=0;i<=r;i++){
 		for(int j=0;j<=g;j++){
 			for(int k=0;k<=b;k++){
 				if(i && j)maxs(dp[i][j][k],dp[i-1][j-1][k]+v1[i-1]*v2[j-1]);
 				if(i && k)maxs(dp[i][j][k],dp[i-1][j][k-1]+v1[i-1]*v3[k-1]);
 				if(j && k)maxs(dp[i][j][k],dp[i][j-1][k-1]+v2[j-1]*v3[k-1]);
 				maxs(a,dp[i][j][k]);
 			}
 		}
 	}
 	cout<<a<<endl;
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