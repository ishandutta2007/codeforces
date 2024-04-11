#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double abs() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
};
ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }
int iSP(Pt a,Pt b,Pt c){
	int s=sig((b-a).det(c-a));
	if(s) return s;//+-1:not intersect
	if(sig((b-a).dot(c-a))<0) return -2;//c-a-b
	if(sig((a-b).dot(c-b))<0) return 2;//a-b-c
	return 0;//a-c-b
}
bool iSS(Pt a,Pt b,Pt c,Pt d){
	return (iSP(a,b,c)*iSP(a,b,d)<=0 && iSP(c,d,a)*iSP(c,d,b)<=0);
}
Pt pLL(Pt a,Pt b,Pt c,Pt d){
	b=b-a;d=d-c;return a+b*(c-a).det(d)/b.det(d);
}
double ret[310];
int a[310][310];
int main()
{
	int n,m;double inf=100000;
	scanf("%d %d",&n,&m);
	rep(i,n) rep(j,m+1) scanf("%d",&a[i][j]);
	rep(i,m){
		double parea=0.5*(a[0][i]+a[0][i+1]);ret[0]+=parea;
		vector<Pt> p;
		p.pb(Pt(0,inf));p.pb(Pt(0,a[0][i]));p.pb(Pt(1,a[0][i+1]));p.pb(Pt(1,inf));
		REP(j,1,n){
			int f=0;
			rep(k,j){if(a[k][i]==a[j][i] && a[k][i+1]==a[j][i+1]) f=1;}
			if(f>0) continue;
			Pt st(0,a[j][i]),go(1,a[j][i+1]);
			vector<Pt> np;int cov=0,npc=0;
			rep(k,p.size()-1){
				if(cov<1) np.pb(p[k]);
				if(iSS(st,go,p[k],p[k+1]) && iSP(st,go,p[k])!=0){
					cov=1-cov;
					np.pb(pLL(st,go,p[k],p[k+1]));npc++;
				}
			}
			if(npc<2) continue;
			np.pb(p[p.size()-1]);
			p.clear();p.pb(np[0]);
			rep(k,np.size()-1){
				if((np[k+1]-np[k]).abs()>EPS) p.pb(np[k+1]);
			}
			
			double narea=0.0;
			rep(k,p.size()-1){
				narea+=0.5*(p[k+1].x-p[k].x)*(p[k+1].y+p[k].y);
			}
			ret[j]+=narea-parea;parea=narea;
			
			//rep(k,p.size()) cerr<<p[k].x<<' '<<p[k].y<<endl;cerr<<endl;
		}
	}
	rep(i,n) printf("%.12f\n",ret[i]);
}