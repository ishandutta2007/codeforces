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
const ll maxn=1e6+10;

bool sp;
map<ll,ll>n,m,s;
ll N,M,S;
ll par[maxn];
ll tavan(ll a,ll b){
	if(b==0)return 1;
	return (b%2?a:1)*tavan(a*a,b/2);
}
void factorize(ll num,map<ll,ll>&mp){
	while(num>1){
		if(par[num]==0){
			mp[num]++;
			return;
		}
		mp[par[num]]++;
		num/=par[num];
	}
}
void Get(map<ll,ll>&mp,ll &num){
	mp.clear();
	ll x1,x2,x3;cin>>x1>>x2>>x3;
	num=x1*x2*x3;
	factorize(x1,mp);
	factorize(x2,mp);
	factorize(x3,mp);
	if(sp)mp[2]++;
}
ll solve1(){
	vector<pll>v;
	vector<ll>T;
	v.clear();T.clear();
	for(map<ll,ll>::iterator it=n.begin();it!=n.end();it++){
		if((it->S)>(s[it->F])){
			v.PB(MP(it->F,s[it->F]));//darge aamele ->F bayad kamtar az ->S bashe
			ll SZ=sz(v)-1;
			T.PB(tavan(v[SZ].F,v[SZ].S+1));
		}
	}
	ll ans=0;
	REP(i,(1<<sz(v))){
		ll zarb=1,alamat=1;
		REP(j,sz(v)){
			if((i>>j)%2){
				alamat*=-1;
				zarb*=T[j];//overflow??
			}
		}
		ans+=alamat*(M/zarb);
	}
	return ans;
}
ll solve2(){
	vector<ll>v;v.clear();
	v.PB(1);
	for(map<ll,ll>::iterator it=s.begin();it!=s.end();it++){
		ll SZ=sz(v),p=it->F,t=it->S;
		REP(i,SZ){
			ll pro=1;
			REP(j,t){
				pro*=p;
				v.PB(v[i]*pro);
			}
		}
	}
	ll ans=0;
	REP(i,sz(v)){
		if(v[i]<=N)
			ans++;
	}
	return ans;
}
int main(){
	for(ll i=2;i<maxn;i++){
		if(par[i]==0){
			for(ll j=i*i;j<maxn;j+=i){
				par[j]=i;
			}
		}
	}
	ll q;cin>>q;
	REP(i,q){
		sp=0;Get(n,N);
		sp=0;Get(m,M);
		sp=1;Get(s,S);
		cout<<solve1()+solve2()<<endl;
	}
}