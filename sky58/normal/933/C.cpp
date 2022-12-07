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
#include<cassert>
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
	bool operator<(const Pt &a) const { return sig(x-a.x)<0 || (sig(x-a.x)==0 && sig(y-a.y)<0); }
	double abs() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
};
ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }
struct seg{
	Pt s,t;
	seg(){}
	seg(Pt s,Pt t): s(s),t(t){}
};
vector<Pt> pCC(Pt a,double r,Pt b,double s){
	vector<Pt> ret;
	double d=(a-b).abs(),x=(d*d+r*r-s*s)/(d*2);
	if(d>r+s+EPS || d<fabs(s-r)-EPS) return ret;
	Pt e=(b-a)/d,w=e*Pt(0,1)*sqrt(max(r*r-x*x,0.0));
	ret.pb(a+e*x-w);
	if(w.abs()>EPS) ret.pb(a+e*x+w);
	return ret;
}
int main()
{
	Pt p[5];double r[5];
	int n,a,b,out=0;cin>>n;
	rep(i,n){
		cin>>a>>b>>r[i];p[i]=Pt(a,b);
	}
	if(n==1){
		cout<<2<<endl;return 0;
	}
	if(n==2){
		if(pCC(p[0],r[0],p[1],r[1]).size()>1) cout<<4<<endl;else cout<<3<<endl;
		return 0;
	}
	rep(i,3){
		int f=0;
		rep(j,3){
			if(i==j) continue;
			if(pCC(p[i],r[i],p[j],r[j]).size()>0) f=1;
		}
		//cout<<i<<' '<<f<<endl;
		if(f==0) out++;
	}
	if(out==3){
		cout<<4<<endl;return 0;
	}
	out+=2;//cout<<out<<endl;
	vector<vector<Pt> > v;
	rep(i,3) REP(j,i+1,3) v.pb(pCC(p[i],r[i],p[j],r[j]));
	rep(i,3){
		out+=v[i].size();
		//rep(j,v[i].size()) cout<<v[i][j];cout<<endl;
	}
	rep(i,v[0].size()) rep(j,v[1].size()){
		if((v[0][i]-v[1][j]).abs()<EPS) out--;
	}
	cout<<out<<endl;
}


/*
int a[5],b[5],r[5];
int sq(int x){
	return x*x;
}
bool di(int i,int j,int r){
	if(sq())
}
int main()
{
	int n;cin>>n;rep(i,n) cin>>a[i]>>b[i]>>r[i];
	if(n==1){
		cout<<2<<endl;return 0;
	}
	if(n==2){
		if(sq(a[0]-a[1])+sq(b[0]-b[1])<sq(r[0]+r[1])) cout<<4<<endl;else cout<<3<<endl;
		return 0;
	}
}
*/