// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll fib[100],dp[100][2];
vector<ll>v;

int main(){
    fib[1]=1,fib[2]=2;
    FOR(i,3,90){
	fib[i]=fib[i-1]+fib[i-2];
    }
    ll t;cin>>t;
    while(t--){
	ll n;cin>>n;
	v.clear();
	memset(dp,0,sizeof dp);
	FORD(i,90,1){
	    if(n>=fib[i])
		v.PB(i),n-=fib[i];
	}
	v.PB(0);
	reverse(all(v));
	dp[0][0]=1;
	FOR(i,1,sz(v)-1){
	    dp[i][0]=dp[i-1][0]+dp[i-1][1];
	    dp[i][1]=dp[i-1][1]*((v[i]-v[i-1])/2)+dp[i-1][0]*((v[i]-v[i-1]-1)/2);
	}
	cout<<dp[sz(v)-1][0]+dp[sz(v)-1][1]<<endl;
    }
}