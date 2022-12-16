// new day,new strength,new thougts
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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

pll a[4],b[4];

inline ll t(ll x){
	return x*x;
}
inline ll ds2(pll x,pll y){
	return t(x.F-y.F)+t(x.S-y.S);
}
inline ll S2(pll x,pll y,pll z){
	return abs((x.F*y.S)+(y.F*z.S)+(z.F*x.S)-(x.F*z.S)-(z.F*y.S)-(y.F*x.S));
}

bool inside1(pll p){
	ll num1=0,num2=0;
	REP(i,4)
		num1+=S2(a[i],a[(i+1)%4],p);
	num2=(2*ds2(a[0],a[1]));
	return (num1==num2);
}

bool inside2(pll p){
	ll num1=0,num2=0;
	REP(i,4)
		num1+=S2(b[i],b[(i+1)%4],p);
	num2=(2*ds2(b[0],b[1]));
	return (num1==num2);
}

int main(){
	REP(i,4)
		cin>>a[i].F>>a[i].S;
	REP(i,4)
		cin>>b[i].F>>b[i].S;
	REP(i,4){
		if(inside1(b[i])){
			cout<<"YES";
			return 0;
		}
	}
	REP(i,4){
		if(inside2(a[i])){
			cout<<"YES";
			return 0;
		}
	}
	pll p=MP(b[0].F+b[2].F,b[0].S+b[2].S);
	REP(i,4)
		a[i]=MP(2*a[i].F,2*a[i].S);
	if(inside1(p)){
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
}