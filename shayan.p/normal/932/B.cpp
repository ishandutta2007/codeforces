// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

#define bug(i) cerr<<i<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e6+10;

#pragma GCC Optimize("Ofast")

ll sum[15][maxn];
ll g[maxn];

ll f(ll num){
	ll ans=1;
	while(num>0){
		ll t=num%10;
		if(t!=0)ans*=t;
		num/=10;
	}
	return ans;
}
ll gg(ll num){
	if(num<10)return num;
	return g[f(num)];
}

int main(){
	FOR(i,1,maxn-1){
		g[i]=gg(i);
		FOR(j,1,9)
			sum[j][i]=sum[j][i-1]+(g[i]==j);
	}
	ll q;cin>>q;
	REP(i,q){
		ll l,r,k;cin>>l>>r>>k;
		cout<<sum[k][r]-sum[k][l-1]<<endl;
	}
}