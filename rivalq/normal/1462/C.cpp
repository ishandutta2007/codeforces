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


int dp[10][51][512];
int vis[10][51][512];
int b[10];
int zeno(int i,int j,int mask){
	if(vis[i][j][mask])return dp[i][j][mask];
	if(j==0)return 0;
	if(i>=9){
		return 1e10;
	}
	vis[i][j][mask]=1;
	dp[i][j][mask]=zeno(i+1,j,mask);
	for(int k=1;k<=min(9LL,j);k++){
		int t=k-1;
		if(((1<<t)&mask)==0){
			mins(dp[i][j][mask],zeno(i+1,j-k,mask|(1<<t))+k*b[8-i]);
		}
	}
	return dp[i][j][mask];
}

int solve(){
 	int x;cin>>x;
 	if(x>45){
 		cout<<-1<<endl;return 0;
 	}
 	mem0(vis);b[0]=1;
 	rep(i,1,9)b[i]=b[i-1]*10;
 	int ans=zeno(0,x,0);
 	if(ans<1e10){
 		cout<<ans<<endl;
 	}
 	else{
 		cout<<-1<<endl;
 	}
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