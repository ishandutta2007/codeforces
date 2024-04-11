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
 	int n;cin>>n;
 	vector<int>a(n+1);
 	vector<vector<int>>dp(n+1,vector<int>(10)),dp2(n+1,vector<int>(10));
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	vector<int>mx(6,-1e18),mn(6,1e18);
 	for(int i=1;i<=5;i++)maxs(mx[1],a[i]),mins(mn[1],a[i]);
 	for(int i=1;i<=5;i++){
 		for(int j=i+1;j<=5;j++){
 			maxs(mx[2],a[i]*a[j]);
 			mins(mn[2],a[i]*a[j]);
 		}
 	}
 	for(int i=1;i<=5;i++){
 		for(int j=i+1;j<=5;j++){
 			for(int k=j+1;k<=5;k++){
 				maxs(mx[3],a[i]*a[j]*a[k]);
 				mins(mn[3],a[i]*a[j]*a[k]);
 			}
 			
 		}
 	}
 	for(int i=1;i<=5;i++){
 		for(int j=i+1;j<=5;j++){
 			for(int k=j+1;k<=5;k++){
 				for(int p=k+1;p<=5;p++){
 					maxs(mx[4],a[i]*a[j]*a[k]*a[p]);
 					mins(mn[4],a[i]*a[j]*a[k]*a[p]);
 				}
 				
 			}
 			
 		}
 	}
 	mx[5]=a[1]*a[2]*a[3]*a[4]*a[5];
 	mn[5]=mx[5];	
 	if(n==5){
 		cout<<mx[5]<<endl;return 0;
 	}	
 	for(int i=6;i<=n;i++){
 		dp[i][1]=a[i];
 		dp2[i][1]=a[i];
 		for(int j=2;j<=5;j++){
 			if(a[i]>=0)dp[i][j]=mx[j-1]*a[i],dp2[i][j]=mn[j-1]*a[i];
 			else dp[i][j]=mn[j-1]*a[i],dp2[i][j]=mx[j-1]*a[i];

 		}
 		for(int j=1;j<=5;j++){
 			maxs(mx[j],dp[i][j]);
 			mins(mn[j],dp2[i][j]);
 		}
 	}
 	cout<<mx[5]<<endl;
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