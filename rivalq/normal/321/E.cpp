#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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
const int maxn=4001;
int a[maxn][maxn];
int c[maxn][maxn];
int p[maxn][maxn];
int opt[maxn][maxn];
int dp[maxn][maxn];
void dc(int i,int l,int r,int tl,int tr){
	if(l>r)return;
	int idx=0;
	int mid=(l+r)/2;
	//cout<<i<<" "<<l<<" "<<r<<endl;
	for(int j=tl;j<=min(tr,i);j++){
		if(dp[i][mid]>c[j][i]+dp[j-1][mid-1]){
			dp[i][mid]=c[j][i]+dp[j-1][mid-1];
			idx=j;
		}
	}
	opt[i][mid]=idx;
	if(l==r){
		return;
	} 
        dc(i,l,mid-1,tl,opt[i][mid]);
        dc(i,mid+1,r,opt[i][mid],tr); 
}
int solve(){
    int n,k;cin>>n>>k;
    rep(i,1,n+1){
    	rep(j,1,n+1){
    		char c;cin>>c;
    		a[i][j]=c-'0';
    		p[i][j]=p[i-1][j]+p[i][j-1]+a[i][j]-p[i-1][j-1];
    	}
    }  
    rep(i,1,n+1){
    	rep(j,i,n+1){
    		c[i][j]=(p[j][j]+p[i-1][i-1]-p[i-1][j]-p[j][i-1])/2;
    	}
    }
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=k;j++)dp[i][j]=1e9;
    }
    dp[0][0]=0;
    //dc(1,1,k,1,k,dp);
    rep(i,1,n+1){
        dc(i,1,min(i,k),1,n);
    }
    cout<<dp[n][k]<<endl;
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