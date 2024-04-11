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
typedef pair<ld,ld> pld;

const ll inf=4e18;
const ll maxn=2e5+10;
const ld eps=0.000000000000001;

#pragma GCC Optimize("Ofast")

bool cmp(double a,double b){
	if(a<b&&(b-a)>eps)return 1;
	return 0;
}

bool cmpld(pld a,pld b){
	if(cmp(a.F,b.F))return 1;
	if(cmp(b.F,a.F))return 0;
	if(cmp(a.S,b.S))return 1;
	return 0;
}
inline ld t(ld a){
	return a*a;
}

bool cmpd(ld a,ld b){
	if(a<b&&(b-a)>eps)
		return 1;
	return 0;
}

struct Cmp{
	bool operator() (pld a,pld b){
		if(cmpd(a.F,b.F))return 1;
		if(cmpd(b.F,a.F))return 0;
		return cmpd(a.S,b.S);
	}
};

map<pld,ll,Cmp> dot;

struct circle{
	ld x,y,r;
	void Get(){
		cin>>x>>y>>r;
	}
	bool test(ld x0,ld y0){
		ld num=t(x-x0)+t(y-y0)-t(r);
		if(abs(num)<eps)
			return 1;
		return 0;
	}
};circle c[4];

pair<ll,pld> solve_eq(ld a,ld b,ld c){
	ld delta=(b*b)-(4*a*c);
	if(abs(delta)<eps)
		delta=0;
	if(delta<0)
		return MP(0,MP(0,0));
	ld sq=sqrt(delta);
	ld ans1=(-b+sq)/(2*a);
	ld ans2=(-b-sq)/(2*a);
	if(delta==0)
		return MP(1,MP(ans1,ans2));
	return MP(2,MP(ans1,ans2));
}

void testx(circle c,ld X,circle cc){
	ld Y=t(c.r)-t(X-c.x);
	if(Y<0)return;
	ld sq=sqrt(Y);
	ld yy=sq+c.y;
	if(c.test(X,yy)&&cc.test(X,yy)){
		dot[MP(X,yy)]++;
	}
	if(sq!=0){
		yy=-sq+c.y;
		if(c.test(X,yy)&&cc.test(X,yy)){
			dot[MP(X,yy)]++;
		}
	}
}

void testy(circle c,ld Y,circle cc){
	ld X=t(c.r)-t(Y-c.y);
	if(X<0)return;
	ld sq=sqrt(X);
	ld xx=sq+c.x;
	if(c.test(xx,Y)&&cc.test(xx,Y)){
		dot[MP(xx,Y)]++;
	}
	if(sq!=0){
		xx=-sq+c.x;
		if(c.test(xx,Y)&&cc.test(xx,Y)){
			dot[MP(xx,Y)]++;
		}
	}
}

void intersect(circle c0,circle c1){
	ld a=2*(c1.x-c0.x);
	ld b=2*(c1.y-c0.y);
	ld c=t(c0.r)-t(c1.r)+t(c1.x)-t(c0.x)+t(c1.y)-t(c0.y);
	if(b==0){
		ld X=c/a;
		testx(c0,X,c1);
		return;
	}
	if(a==0){
		ld Y=c/b;
		testy(c0,Y,c1);
		return;
	}
	ld A=1+(t(a)/t(b));
	ld B=(-2)*(c0.x);B-=(2*a*c)/t(b);B+=(2*(a*(c0.y)))/b;
	ld C=t(c0.x)+t(c0.y)+((t(c)/t(b)))-((2*c*(c0.y))/b)-t(c0.r);
	
	pair<ll,pair<ld,ld> > p=solve_eq(A,B,C);
	if(p.F==1){
		testx(c0,p.S.F,c1);
	}
	if(p.F==2){
		testx(c0,p.S.F,c1);
		testx(c0,p.S.S,c1);
	}
}

bool out_in(circle a,circle b){
	ld dis2=t(a.x-b.x)+t(a.y-b.y);
	if(dis2<t(a.r-b.r)||dis2>t(a.r+b.r))
		return 1;
	return 0;
}

bool momas(circle a,circle b){
	ld dis2=t(a.x-b.x)+t(a.y-b.y);
	if(dis2==t(a.r-b.r)||dis2==t(a.r+b.r))
		return 1;
	return 0;
}

ll  solve2(circle a,circle b){
	if(out_in(a,b)||momas(a,b))
		return 3;
	return 4;
}

int main(){
	ll n;cin>>n;
	REP(i,n)
		c[i].Get();
		
	if(n==1){
		cout<<2;
		return 0;
	}
	if(n==2){
		cout<<solve2(c[0],c[1]);
		return 0;
	}
	if(out_in(c[0],c[1])&&out_in(c[0],c[2])){
		cout<<1+solve2(c[1],c[2]);
		return 0;
	}
	if(out_in(c[1],c[0])&&out_in(c[1],c[2])){
		cout<<1+solve2(c[0],c[2]);
		return 0;
	}
	if(out_in(c[2],c[0])&&out_in(c[2],c[1])){
		cout<<1+solve2(c[0],c[1]);
		return 0;
	}
	
	FOR(i,0,n-1)
		FOR(j,0,n-1)
			if(i!=j)
				intersect(c[i],c[j]);
	ll sm=0;
	for(map<pair<ld,ld>,ll> :: iterator it=dot.begin();it!=dot.end();it++){
		if(it->S==2)sm+=2;
		if(it->S==6)sm+=3;
	}
	cout<<(sm-sz(dot))+2;
}