// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c.size())
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10;
const ll mod=1e9+7;
const ll P1=19,P2=137;
const ll Big=2e5;

string str;
pll t[maxn],hsh[maxn];

pll get_hash(ll l,ll r){
	if(r>=(sz(str))) r=sz(str)-1;
	if(l==0)return hsh[r];
	ll ff=(((hsh[r].F-hsh[l-1].F*t[r-l+1].F)%mod)+mod)%mod;
	ll ss=(((hsh[r].S-hsh[l-1].S*t[r-l+1].S)%mod)+mod)%mod;
	return MP(ff,ss);
}

ll id[maxn];// 1 base
pll idp[maxn];
ll p[maxn];
pair<pll,ll>tmp[maxn];

inline ll Cn2(ll x){
	return (x*(x-1))/2;
}
ll solve(ll f,ll s,ll ln){
	if(f==s){
		return sz(str)-(p[f]+ln);
	}
	ll l=1,r=Big,an=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(get_hash(p[f],p[f]+mid-1)==get_hash(p[s],p[s]+mid-1)){
			an=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	l=f;r=s;
	ll pos=f;
	while(l<=r){
		ll mid=(l+r)/2;
		ll val1=((p[f]+an)>=sz(str)?0:int(str[p[f]+an]));
		ll val2=((p[mid]+an)>=sz(str)?0:int(str[p[mid]+an]));
		if(val1==val2){
			pos=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	ll num=solve(f,pos,an)+solve(pos+1,s,an)+Cn2(s-f+2)*(an-ln);
	return num;
}

int main(){
	t[0]=MP(1,1);
	FOR(i,1,maxn-1){
		t[i]=MP((t[i-1].F*P1)%mod,(t[i-1].S*P2)%mod);
	}
	cin>>str;
	pll bf=MP(0,0);
	REP(i,sz(str)){
		hsh[i]=MP((bf.F*P1+str[i]-'a'+1)%mod,(bf.S*P2+str[i]-'a'+1)%mod);
		bf=hsh[i];
	}
	// suffix array start
	REP(i,sz(str)){
		id[i]=str[i];
	}
	REP(j,19){
		ll tw=(1<<j);
		REP(i,sz(str)){
			tmp[i].F.F=id[i];
			tmp[i].F.S=((i+tw)>=(sz(str))?0:id[i+tw]);
			tmp[i].S=i;
		}
		sort(tmp,tmp+sz(str));
		pll bf=MP(-1,-1);
		ll H=0;
		REP(i,sz(str)){
			H+=(bf!=tmp[i].F);
			bf=tmp[i].F;
			id[tmp[i].S]=H;
		}
	}
	REP(i,sz(str)){
		idp[i]=MP(id[i],i);
	}
	sort(idp,idp+sz(str));
	REP(i,sz(str)){
		p[i]=idp[i].S;
	}
	// suffix array end
	// now p[i].F= ith lexically suffix    from where to start
	
	cout<<solve(0,sz(str)-1,0);
}