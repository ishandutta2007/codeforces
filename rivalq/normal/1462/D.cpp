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

const int N=3005;

int dp[N][N];
int vis[N][N];
int a[N];
int n;
int zeno(int i,int j){
	if(vis[i][j])return dp[i][j];
	if(i==n)return 0;
	vis[i][j]=1;
	dp[i][j]=n;
	int s=a[i]-a[j-1]; // j....i
	//cout<<"#"<<s<<" "<<i<<" "<<j<<endl;
	for(int k=i+1;k<=n;k++){
		if(a[k]-a[i]==s){
			mins(dp[i][j],zeno(k,i+1)+k-i-1);
		}
	}	
	return dp[i][j];
}


int solve(){
 	cin>>n;a[0]=0;
	rep(i,1,n+1){
		cin>>a[i];a[i]+=a[i-1];
		rep(j,1,n+1)vis[i][j]=0;
	} 
	int ans=n;
	rep(i,1,n+1){
		mins(ans,zeno(i,1)+i-1);
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}