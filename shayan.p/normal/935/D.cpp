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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn],b[maxn];
pll Ans=MP(0,1);

pll gcd(ll a,ll b){
	if(b==0) return MP(a,0);
	pll p=gcd(b,a%b);
	return MP(p.S,p.F-((a/b)*p.S));
}
ll inv(ll a) {
	return (gcd(a,mod).F+mod)%mod;
}

void pl(pll num){
	num.F%=mod;
	num.S%=mod;
	Ans.F=((Ans.F*num.S)+(Ans.S*num.F))%mod;
	Ans.S=(Ans.S*num.S)%mod;
}

void print(){
	cout<<(Ans.F*inv(Ans.S))%mod;
	exit(0);
}

int main(){
	ll n,m;cin>>n>>m;
	REP(i,n)
		cin>>a[i];
	REP(i,n)
		cin>>b[i];
	pll same=MP(1,1);
	REP(i,n){
		if(a[i]!=0&&b[i]!=0){
			if(a[i]<b[i]){
				print();
			}
			if(a[i]>b[i]){
				pl(same);
				print();
			}
		}
		else if(a[i]==0&&b[i]==0){
			pl(MP(same.F*(m-1),same.S*(2*m)));
			same.S=(same.S*m)%mod;
		}
		else if(a[i]==0){
			pl(MP(same.F*(m-b[i]),same.S*m));
			same.S=(same.S*m)%mod;
		}
		else if(b[i]==0){
			pl(MP(same.F*(a[i]-1),same.S*m));
			same.S=(same.S*m)%mod;
			
		}
	}
	print();
}