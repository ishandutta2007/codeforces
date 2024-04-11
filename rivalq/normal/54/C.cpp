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

int powb(int x,int b){
	if(x==0)return 1;
	return b*powb(x-1,b);
}


const int N=2000;

double dp[N][N];

int solve(){
	auto func=[&](int x){
		if(x==0)return 0LL;
		string s = to_string(x);
		int n = s.length();
		int res = (powb(n-1,10)-1)/9;
		int val = powb(n-1,10);
		if(s[0]=='1'){
			res += x-val+1;
		}
		else{
			res += val;
		}
		return res;

	};
 	int n;cin>>n;
 	vector<int>a(n+1),b(n+1);
 	rep(i,1,n+1){
 		int l,r;cin>>l>>r;
 		b[i] = r-l+1;
 		a[i] = func(r) - func(l-1);
 	}
 	int k;cin>>k;
 	dp[0][0]=1;
 	for(int i=1;i<=n;i++){
 		double p = a[i];
 		double l = b[i];
 		p/=l;
 		dp[i][0]=dp[i-1][0]*(1-p);
 		for(int j=1;j<=i;j++){
 			dp[i][j]=p*dp[i-1][j-1]+(1-p)*dp[i-1][j];
 		}
 	}
 	k*=n;
 	if(k%100==0){
 		k/=100;
 	}
 	else{
 		k=k/100+1;
 	}
 	double ans = 0;
 	for(int j=k;j<=n;j++){
 		ans += dp[n][j];
 	}
 	cout<<fixed<<setprecision(10)<<ans<<endl;
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