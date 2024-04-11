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
const ll maxn=2e5+10;

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
struct Frac{
	ll x,y;
	Frac(ll a,ll b){
		x=a;
		y=b;
		normal();
	}
	void normal(){
		bool is=((x<0)xor(y<0));
		ll g=gcd(abs(x),abs(y));
		x=abs(x)/g;
		y=abs(y)/g;
		if(is)x*=-1;
	}
};
Frac make_f(ll a){
	Frac f(a,1);
	return f;
}
Frac operator+(Frac a,Frac b){
	ll q=a.x*b.y,w=a.y*b.x,e=a.y*b.y;
	Frac f(q+w,e);
	return f;
}
Frac operator*(Frac a,Frac b){
	a.x*=b.x;
	a.y*=b.y;
	a.normal();
	return a;
}
Frac operator-(Frac a,Frac b){
	b.x*=-1;
	return a+b;
}
Frac operator/(Frac a,Frac b){/////// b shouldnt be zeroooo
	if(b.x==0){
		cerr<<"makhraj 0 shode\n";
		exit(0);
	}
	swap(b.x,b.y);
	return a*b;
}
bool operator==(Frac a,Frac b){
	return (a.x==b.x)&&(a.y==b.y);
}
bool operator>(Frac a,Frac b){
	Frac f=a-b;
	return f.x>0;
}
bool operator<(Frac a,Frac b){
	return b>a;
}
bool operator<=(Frac a,Frac b){
	return (a<b)||(a==b);
}
bool operator>=(Frac a,Frac b){
	return (a>b)||(a==b);
}

inline ll f(int num){
	return 180*(num-2);
}
inline Frac g(int num){
	return make_f(f(num))/make_f(num);
}
Frac abs(Frac a){
	if(a.x<0)a.x*=-1;
	return a;
}
int main(){
	ll n,D;cin>>n>>D;
	Frac d=make_f(D);
	Frac ans(360,1);
	ll ansind=2;
	REP(i,n-2){
		Frac deg(1,1);
		deg=g(n)-((make_f(f(i+2))-(make_f(i)*g(n)))/make_f(2));
		if(abs(d-deg)<=abs(d-ans)){
			ans=deg;
			ansind=(i+2)%n;
		}
	}
	cout<<1<<" "<<2<<" "<<ansind+1;
}