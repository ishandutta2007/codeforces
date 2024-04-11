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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

struct fraction{
	ll q,w;
	fraction(){
		q=0;w=1;
	}
	ll gcd(ll a,ll b){
		if(b==0)return a;
		return gcd(b,a%b);
	}
	void normalize(){
		ll g=gcd(abs(q),abs(w));
		q/=g;
		w/=g;
		bool alamat=(q<0 xor w<0);
		if(alamat){
			q=abs(q);
			w=-abs(w);
		}
		else{
			q=abs(q);
			w=abs(w);
		}
	}
};
fraction operator+(fraction a,fraction b){
	fraction c;
	c.q=(a.q*b.w)+(a.w+b.q);
	c.w=(a.w*b.w);
	c.normalize();
	return c;
}
fraction operator-(fraction a,fraction b){
	b.q*=-1;
	return a+b;
}
fraction operator*(fraction a,fraction b){
	a.q*=b.q;
	a.w*=b.w;
	a.normalize();
	return a;
}
fraction operator/(fraction a,fraction b){
	if(b.w==0){
		cerr<<"Math error";
		exit(0);
	}
	fraction c;
	c.q=b.w;
	c.w=b.q;
	return a*c;
}
bool operator<(fraction a,fraction b){
	return (a.q*b.w)<(a.w*b.q);
}
bool operator==(fraction a,fraction b){
	return ((a.q==b.q)&&(a.w==b.w));
}
bool operator!=(fraction a,fraction b){
	return !(a==b);
}

typedef pair<fraction,fraction> pff;

pff p[maxn];

bool cmp(pff a,pff b){
	if(a.F!=b.F)
		return a.F<b.F;
	return b.S<a.S;
}

ll inversion(vector<fraction>&vec){
	ll n=sz(vec);
	if(n<2)
		return 0;
	vector<fraction>a,b;
	a.clear();
	b.clear();
	ll mid=n/2;
	REP(i,mid)
		a.PB(vec[i]);
	FOR(i,mid,(n-1))
		b.PB(vec[i]);
	ll ans=0;
	ans+=inversion(a);
	ans+=inversion(b);
	vec.clear();
	ll pa=0,pb=0;
	while((pa+pb)<n){
		if(pa==sz(a)){
			vec.PB(b[pb++]);
		}
		else if(pb==sz(b)){
			vec.PB(a[pa++]);
			ans+=pb;
		}
		else{
			if(a[pa]<b[pb]){
				vec.PB(a[pa++]);
				ans+=pb;
			}
			else{
				vec.PB(b[pb++]);
			}
		}
	}
	return ans;
}

int main(){
	ll n,w;cin>>n>>w;
	REP(i,n){
		ll x,v;cin>>x>>v;
		bool state=(x<0);
		x=abs(x);
		v=abs(v);
		fraction f;
		f.q=x;
		f.w=v+w;
		f.normalize();
		p[i].F=f;
		f.q=x;
		f.w=v-w;
		f.normalize();
		p[i].S=f;
		if(state){
			swap(p[i].F,p[i].S);
		}
	}
	sort(p,p+n,cmp);
	vector<fraction>vec;
	REP(i,n)
		vec.PB(p[i].S);
	cout<<inversion(vec);
}