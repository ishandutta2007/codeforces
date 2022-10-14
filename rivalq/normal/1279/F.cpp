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
 	int n,k,l;cin>>n>>k>>l;
 	string s;cin>>s;
 	vector<int>a(n+1);
 	int ans=n;
 	auto func=[&](int x){
 		vector<pii>dp(n+1,{1e9,0});
 		dp[0].x=0;
 		for(int i=0;i<n;i++){
 			if(dp[i+1]>make_pair(dp[i].x+a[i],dp[i].y)){
 				dp[i+1]=make_pair(dp[i].x+a[i],dp[i].y);
 			}
 			if(dp[min(i+l,n)]>make_pair(dp[i].x+x,dp[i].y+1)){
 				dp[min(i+l,n)]=make_pair(dp[i].x+x,dp[i].y+1);
 			}
 		}
 		return dp[n];
 			 		
 	};
 	auto solve=[&](){
 		int L=0,R=n+1;
 		int c=0;
 		while(L<=R){
 			int M=(L+R)/2;
 			pii p=func(M);
 			if(p.y>k){
 				L=M+1;
 				c=M;
 			}
 			else{
 				R=M-1;
 			}
 		}
 		pii p=func(c);
 		if(p.y<=k)return 0LL;
 		p=func(c+1);
 		return p.x-k*(c+1);

 	};
 	for(int i=0;i<n;i++){
 		a[i]=isupper(s[i])>0;
 	}
 	mins(ans,solve());
 	for(int i=0;i<n;i++){
 		a[i]=islower(s[i])>0;
 	}
 	mins(ans,solve());
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