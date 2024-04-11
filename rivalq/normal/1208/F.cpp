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


const int N=(1<<21);
const int M=N-1;

pii dp[N];

int solve(){
 	int n;cin>>n;
 	vector<int>a(n+1);
 	auto add=[&](int mask,int j){
 		if(dp[mask].x==-1)dp[mask].x=j;
 		else if(dp[mask].y==-1){
 			dp[mask].y=j;
 			if(dp[mask].y<dp[mask].x)swap(dp[mask].x,dp[mask].y);
 		}
 		else if(dp[mask].y<j){
 			dp[mask].x=dp[mask].y;
 			dp[mask].y=j;
 		}
 		else if(dp[mask].x<j && j!=dp[mask].y){
 			dp[mask].x=j;
 		}
 	};
 	rep(i,1,n+1){
 		cin>>a[i];
 		add(a[i],i);	
 	}	
 	rep(i,0,21){
 		rep(mask,0,N){
 			if((mask)&(1<<i)){
 				if(dp[mask].x!=-1)add(mask^(1<<i),dp[mask].x);
 				if(dp[mask].y!=-1)add(mask^(1<<i),dp[mask].y);

 			}
 		}
 	}
 	int ans=0;
 	rep(i,1,n+1){
 		int rev_mask=M-a[i];
 		int best=0;
 		for(int j=20;j>=0;j--){
 			if(rev_mask&(1<<j)){
 				if(dp[best^(1<<j)].y!=-1 && dp[best^(1<<j)].x>i){
 					best^=(1<<j);
 				}
 			}
 		}
 		if(i+2<=n)maxs(ans,a[i]+best);
 	}
 	cout<<ans<<endl;
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