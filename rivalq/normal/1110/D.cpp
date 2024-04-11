#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
//#define int            long long
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


const int N=1e6+5;

int dp[N][5][3];
int n,m;
int a[N];

int zeno(int i,int j,int k){
	if(i>m)return 0;
	if(dp[i][j][k]!=-1)return dp[i][j][k];
	dp[i][j][k]=0;
	int f1=a[i]-j,f2=a[i+1]-k,f3=a[i+2];
	// we need only two i,i+1,i+2
	for(int t=0;t<=min({f1,f2,f3,2});t++){
		maxs(dp[i][j][k],(f1-t)/3+t+zeno(i+1,k+t,t));
	}
	return dp[i][j][k];
}



int solve(){
	 	cin>>n>>m;
	 	rep(i,1,n+1){
	 		int t;cin>>t;
	 		a[t]++;
	 	}
	 	mem1(dp);
	 	cout<<zeno(1,0,0)<<endl;
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