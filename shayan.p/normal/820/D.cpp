// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=2e6+10;

ll num[maxn],n,neg,pos,tot;
inline ll hf(ll num){
	return num+n-1;
}
inline ll hhf(ll num){
	return num-n+1;
}
deque<ll>d,p;
int main(){
	cin>>n;
	REP(i,n){
		ll x;cin>>x;
		p.PB(x);
		num[hf(x-i-1)]++;
	}
	REP(i,2*n-1){
		d.PB(num[i]);
		if(hhf(i)<=0)neg+=num[i];
		else pos+=num[i];
		tot+=num[i]*abs(hhf(i));
	}
	ll ans=tot,ansind=0,New=tot;
	FOR(i,1,n-1){
		neg-=(p[n-1]-n<=0);
		pos-=(p[n-1]-n>0);
		New+=(neg-pos);
		New-=abs(p[n-1]-n);
		New+=abs(p[n-1]-1);
		d[hf(p[n-1]-n)]--;
		pos-=d[hf(1)];
		neg+=d[hf(1)];
		d.pop_front();
		d.push_back(0);
		d[hf(p[n-1]-1)]++;
		pos+=(p[n-1]-1>0);
		neg+=(p[n-1]-1<=0);
		p.push_front(p.back());
		p.pop_back();
		if(New<ans){
			ans=New;
			ansind=i;
		}
	}
	cout<<ans<<" "<<ansind;
}