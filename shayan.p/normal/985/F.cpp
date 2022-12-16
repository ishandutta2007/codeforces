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
const ll P1=911382323;
const ll P2=972663749;

#pragma GCC Optimize("Ofast")

string s;
ll pp1[maxn],pp2[maxn];
vector<pll>v1,v2;

struct Alpha{
	ll hsh1[maxn],hsh2[maxn];
	void build(char ch){
		REPD(i,sz(s)){
			bool b=(s[i]==ch);
			hsh1[i]=((hsh1[i+1]*P1)+(37*b))%mod;
			hsh2[i]=((hsh2[i+1]*P2)+(43*b))%mod;
		}
	}
	pll ask(ll l,ll ln){// should be 0 base
		ll A1=hsh1[l]-(pp1[ln]*hsh1[l+ln]);
		ll A2=hsh2[l]-(pp2[ln]*hsh2[l+ln]);
		A1=((A1%mod)+mod)%mod;
		A2=((A2%mod)+mod)%mod;
		return MP(A1,A2);
	}
};Alpha alpha[27];

int main(){
	pp1[0]=pp2[0]=1;
	FOR(i,1,maxn-1){
		pp1[i]=(pp1[i-1]*P1)%mod;
		pp2[i]=(pp2[i-1]*P2)%mod;
	}
	ll n,q;scanf("%lld%lld",&n,&q);
	cin>>s;
	REP(i,26)
		alpha[i].build('a'+i);
		
	while(q--){
		ll a,b,ln;scanf("%lld%lld%lld",&a,&b,&ln);
		v1.clear();v2.clear();
		REP(i,26){
			v1.PB(alpha[i].ask(a-1,ln));
			v2.PB(alpha[i].ask(b-1,ln));
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		if(v1==v2)
			printf("YES\n");
		else
			printf("NO\n");
	}
}