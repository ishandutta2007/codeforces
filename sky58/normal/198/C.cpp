#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double pi=3.14159265358979,EPS=1e-9;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

typedef vector<P> G;

struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};

bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
double cal(double t){
	t=fabs(t);
	if(t>2*pi) t-=2*pi;
	if(t>2*pi) t-=2*pi;
	if(t>2*pi) t-=2*pi;
	if(t>2*pi) t-=2*pi;
	t=fabs(t);return min(t,2*pi-t);
}
int main()
{
	double xp,yp,vp,x,v,y,r,R,sita,sita2,sitax,sitay,dx,dy,lo=0.0,hi=1e10;int i;
	cin>>xp>>yp>>vp;
	cin>>x>>y>>v>>r;
	P gen,now;gen.real()=gen.imag()=0.0;now.real()=x;now.imag()=y;
	R=sqrt(xp*xp+yp*yp);sita=atan2(yp,xp);sita2=atan2(y,x);
	sitax=acos(r/R);sitay=acos(r/sqrt(x*x+y*y));dx=sqrt(R*R-r*r);dy=sqrt(x*x+y*y-r*r);
	rep(i,100){
		double mi=(lo+hi)/2,nsita=sita+vp*mi/R,dist;
		P nows;nows.real()=R*cos(nsita);nows.imag()=R*sin(nsita);
		L nowl(now,nows);
		if(distanceSP(nowl,gen)>r) dist=abs(now-nows);
		else{
			double ko=min(min(cal(sita2-nsita-sitax-sitay),cal(sita2-nsita-sitax+sitay)),
							min(cal(sita2-nsita+sitax-sitay),cal(sita2-nsita+sitax+sitay)));
			dist=ko*r+dx+dy;//cout<<ko<<endl;
		}
		//cout<<mi<<' '<<nsita<<' '<<abs(now-nows)<<' '<<dist<<endl;
		if(dist/v<mi) hi=mi;else lo=mi;
	}
	printf("%.12f\n",lo);
	return 0;
}