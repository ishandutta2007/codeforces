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
bool comp(Pt a,Pt b){return a.x<b.x?true:a.y<b.y;}

int iSP(Pt a,Pt b,Pt c){
	int s=sig((b-a).det(c-a));
	if(s) return s;//+-1:not intersect
	if(sig((b-a).dot(c-a))<0) return -2;//c-a-b
	if(sig((a-b).dot(c-b))<0) return 2;//a-b-c
	return 0;//a-c-b
}
int iLL(Pt a,Pt b,Pt c,Pt d){
	if(sig((b-a).dot(d-c))) return 1;//intersect
	if(sig((b-a).dot(c-a))) return 0;//parallel
	return -1;//correspond
}
bool iLS(Pt a,Pt b,Pt c,Pt d){
	return (sig(tri(a,b,c))*sig(tri(a,b,d))<=0);
}
bool iSS(Pt a,Pt b,Pt c,Pt d){
	return (iSP(a,b,c)*iSP(a,b,d)<=0 && iSP(c,d,a)*iSP(c,d,b)<=0);
}
bool iSSstrict(Pt a,Pt b,Pt c,Pt d){
	return (sig(tri(a,b,c))*sig(tri(a,b,d))<0 && sig(tri(c,d,a))*sig(tri(c,d,b))<0);
}
Pt pLL(Pt a,Pt b,Pt c,Pt d){
	b=b-a;d=d-c;return a+b*(c-a).det(d)/b.det(d);
}
double dLP(Pt a,Pt b,Pt c){
	return abs(tri(a,b,c))/(b-a).abs();
}
double dSP(Pt a,Pt b,Pt c){
	if(sig((b-a).dot(c-a))<=0) return (c-a).abs();
	if(sig((a-b).dot(c-b))<=0) return (c-b).abs();
	return abs(tri(a,b,c))/(b-a).abs();
}
double dLL(Pt a,Pt b,Pt c,Pt d){
	return iLL(a,b,c,d)?0:dLP(a,b,c);
}
double dLS(Pt a,Pt b,Pt c,Pt d){
	return iLS(a,b,c,d)?0:min(dLP(a,b,c),dLP(a,b,d));
}
double dSS(Pt a,Pt b,Pt c,Pt d){
	return iSS(a,b,c,d)?0:min(min(dSP(a,b,c),dSP(a,b,d)),min(dSP(c,d,a),dSP(c,d,b)));
}
int convexHull(int n, Pt p[], Pt q[]) {
	int m=0,i,r;
	sort(p,p+n,comp);
	for(i=0;i<n;q[m++]=p[i++]) for(;m>1 && sig(tri(q[m-2],q[m-1],p[i]))<=0;--m);
	for(i=n-2,r=m;i>=0;q[m++]=p[i--]) for(;m>r && sig(tri(q[m-2],q[m-1],p[i]))<=0;--m);
	return m-1;
}

//in:+1 out:-1 on:0
int sGP(int n, Pt p[], Pt a) {
	int side = -1, i;
	p[n]=p[0];
	for(i=0;i<n;++i){
		Pt p0=p[i]-a,p1=p[i+1]-a;
		if(sig(p0.det(p1))==0 && sig(p0.dot(p1))<=0) return 0;
		if(p0.y>p1.y) swap(p0,p1);
		if(sig(p0.y)<=0 && 0<sig(p1.y) && sig(p0.det(p1))>0) side=-side;
	}
	return side;
}
bool ok[364][364];
lint dp[364][364];
Pt P[364];
lint cal(int a,int b){
	if(dp[a][b]>=0) return dp[a][b];
	if(a+1==b) return dp[a][b]=1;
	if(a+2==b){
		if(ok[a][b]) return dp[a][b]=1;return dp[a][b]=0;
	}
	lint ret=0,mo=1000000007;
	REP(i,a+1,b){
		if(ok[a][i] && ok[b][i]) ret=(ret+cal(a,i)*cal(i,b))%mo;
	}
	//cout<<a<<' '<<b<<' '<<ret<<endl;
	return dp[a][b]=ret;
}
int main()
{
	int n,x,y;
	cin>>n;
	rep(i,n){
		cin>>x>>y;P[i]=Pt(x,y);
	}
	memset(ok,false,sizeof(ok));
	memset(dp,-1,sizeof(dp));
	rep(i,n) rep(j,n){
		if(i==j) continue;
		ok[i][j]=true;
		if(sGP(n,P,(P[i]+P[j])*0.5)<0) ok[i][j]=false;
		rep(k,n){
			if(i!=k && j!=k && dSP(P[i],P[j],P[k])<EPS) ok[i][j]=false;
			int l=(k+1)%n;
			if(i!=k && j!=k && l!=i && l!=j && iSS(P[i],P[j],P[k],P[l])) ok[i][j]=false;
		}
		//if(ok[i][j] && abs(i-j)>1) cout<<i<<' '<<j<<endl;
	}
	cout<<cal(0,n-1)<<endl;
}