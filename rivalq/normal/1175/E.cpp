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

const int N=5e5+5; 

int a[N];
int dp[N][21];

int solve(){
 	int n,m;cin>>n>>m;
 	vector<pii>v(n);
 	rep3(n){
 		cin>>v[i];
 	}
 	sort(all(v));
 	int mx=0,j=0;
 	rep(i,0,N){
 		while(j<n && v[j].x<=i){
 			maxs(mx,v[j].y);
 			j++;
 		}
 		a[i]=mx;
 		dp[i][0]=mx;
 	}
 	for(int j=1;j<=20;j++){
 		for(int i=0;i<N;i++){
 			dp[i][j]=dp[dp[i][j-1]][j-1];
 		}
 	}
 	rep3(m){
 		int x,y;cin>>x>>y;
 		int ans=0;
 		if(dp[x][20]<y){
 			cout<<-1<<endl;continue;
 		}
 		for(int i=20;i>=0;i--){
 			if(dp[x][i]<y){
 				ans+=(1<<i);
 				x=dp[x][i];
 			}
 		}
 		cout<<ans+1<<endl;
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}