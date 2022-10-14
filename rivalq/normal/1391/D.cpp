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
#define pc(x)          __builtin_popcount(x)
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	int n,m;cin>>n>>m;
 	if(min(n,m)>=4){
 		cout<<-1<<endl;return 0;
 	}
 	if(min(n,m)<2){
 		cout<<0<<endl;return 0;
 	}
 	vector<vector<int>>a(n+1,vector<int>(m+1));
 	rep(i,1,n+1){
 		rep(j,1,m+1){
 			char c;cin>>c;
 			a[i][j]=c-48;
 		}
 	}
 	vector<vector<int>>b(max(n,m)+1,vector<int>(min(n,m)+1));
 	vector<int>msk(max(n,m)+1);
 	if(n>=m){
 		b=a;
 	}
 	else{
 		rep(i,1,m+1){
 			rep(j,1,n+1){
 				b[i][j]=a[j][i];
 			}
 		}
 	}
 	if(n<m)swap(n,m);
 	rep(i,1,n+1){
 		rep(j,1,m+1){
 			msk[i]+=(1<<(j-1))*b[i][j];
 		}
 	}
 	vector<vector<int>>dp(n+1,vector<int>(1<<m,hell));
 	rep(j,0,(1<<m)){
 		dp[1][j]=pc(msk[1]^j);
 	}
 	auto check=[&](int msk1,int msk2){
 		for(int j=0;j<m-1;j++){
 			int cnt=pc(((1<<j)&msk1))+pc(((1<<j)&msk2));
 			int val=(1<<(j+1));
 			cnt+=(pc(val&msk1))+pc((val&msk2));
 			if(cnt%2==0)return 0;
 		}
 		return 1;
 	};
 	rep(i,2,n+1){
 		rep(k,0,(1<<m)){
 			rep(j,0,(1<<m)){
 				if(check(j,k)){
 					mins(dp[i][j],pc(j^msk[i])+dp[i-1][k]);
 				}
 				
 			}
 		}
 	}
 	int ans=hell;
 	rep(j,0,(1<<m))mins(ans,dp[n][j]);
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