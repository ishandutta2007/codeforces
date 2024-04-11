#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define S second
#define F first
//#define cin fin
//std::ifstream fin("my code.txt");
using namespace std;
const ll mod=1e9+7;
ll tavan(ll a,ll b) {if(b==0) return 1;return (((b%2)?a:1)*tavan((a*a)%mod,b/2))%mod;}
pll gcd(ll a,ll b) {if(b==0) return MP(a,0);pll p=gcd(b,a%b);return MP(p.S,p.F-((a/b)*p.S));}
ll varoon(ll a) {return (gcd(a,mod).F+mod)%mod;}
int main()
{
	string a;ll t,sum=0;cin>>a>>t;
	for(ll i=0;i<a.size();i++) if(a[i]=='0'||a[i]=='5') {sum+=tavan(2,i);sum%=mod;}
	ll q=tavan(2,a.size());
	ll ans1=(((sum*(tavan(q,t)-1))%mod)*varoon(q-1))%mod;
	cout<<ans1;
//	ll ans2=0;for(ll i=0;i<t;i++) {ans2+=sum;sum*=q;ans2%=mod;sum%=mod;}
}