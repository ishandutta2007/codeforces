#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e6+10,mod=1e9+7;
string a,b;
ll cnt[30],fact[maxn];
pll gcd(ll a,ll b) {if(b==0) return MP(a,0);pll p=gcd(b,a%b);return MP(p.S,p.F-((a/b)*p.S));}
ll varoon(ll a) {return (((gcd(a,mod).F)%mod)+mod)%mod;}
ll safe(ll a,ll b,ll c){return (((a*b)%mod)*c)%mod;}
ll f(string &st){
	ll ans=0;
	ll tot=fact[a.size()];
	for(ll i=0;i<26;i++)cnt[i]=0;
	for(ll i=0;i<a.size();i++)cnt[a[i]-'a']++;
	for(ll i=0;i<26;i++)tot=(tot*varoon(fact[cnt[i]]))%mod;
	for(ll i=0;i<st.size();i++){
		ll N=varoon(a.size()-i);
		for(ll j=0;j<st[i]-'a';j++){
			if(cnt[j]==0)continue;
			ans+=safe(tot,N,cnt[j]);
			ans%=mod;
		}
		if(cnt[st[i]-'a']==0)break;
		tot=safe(tot,N,cnt[st[i]-'a']);
		cnt[st[i]-'a']--;
	}
	return ((ans%mod)+mod)%mod;
}
int main()
{
	fact[0]=1;for(ll i=1;i<maxn;i++)fact[i]=(fact[i-1]*i)%mod;
	cin>>a>>b;
	cout<<(((f(b)-f(a)-1)%mod)+mod)%mod;
}