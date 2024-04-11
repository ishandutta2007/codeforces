// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=110;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll tw[maxn];

int main(){
	tw[0]=1;
	FOR(i,1,maxn-1)
		tw[i]=(2*tw[i-1])%mod;
		
	string s;cin>>s;
	ll ans=0,t=1;
	REP(i,sz(s)){
		if(s[i]=='1')
			ans=(ans+tw[sz(s)-1]*tw[sz(s)-i-1])%mod;
	}
	cout<<ans;
}