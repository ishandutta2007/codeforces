//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)
#define DREP(a)						sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)				lower_bound(all(arr),ind)-arr.begin())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;

struct Point3
{
	double x,y,z;
	
	Point3(double _x=0, double _y=0, double _z=0)
	{
		x=_x;
		y=_y;
		z=_z;
	}
	
	bool operator == (Point3 other)
	{
		return abs(x-other.x)<EPS && abs(y-other.y)<EPS && abs(z-other.z)<EPS;
	}
	
	bool operator != (Point3 other)
	{
		return abs(x-other.x)>EPS || abs(y-other.y)>EPS || abs(z-other.z)>EPS;
	}
	
	double length()
	{
		return sqrt(x*x + y*y + z*z);
	}
	
	Point3 operator * (double k)
	{
		return Point3(k*x, k*y, k*z);
	}
	
	Point3 normalize()
	{
		return (*this) * (1/length());
	}
	
	Point3 operator + (Point3 other)
	{
		return Point3(x+other.x, y+other.y, z+other.z);
	}
	
	Point3 operator - (Point3 other)
	{
		return Point3(x-other.x, y-other.y, z-other.z);
	}
	
	double dist(Point3 other)
	{
		return (*this-other).length();
	}
	
	double operator ^ (Point3 other)
	{
		return x*other.x + y*other.y + z*other.z;
	}
	
	Point3 operator * (Point3 other)
	{
		return Point3(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x);
	}
	
	void display()
	{
		printf("Point3 (%lf , %lf , %lf)\n",x,y,z);
	}
};

Point3 operator * (double k,Point3 p)
{
	return Point3(k*p.x, k*p.y, k*p.z);
}

struct Point2
{
	double x,y;
	
	Point2(double _x=0, double _y=0)
	{
		x=_x;
		y=_y;
	}
	
	double length()
	{
		return sqrt(x*x + y*y);
	}
	
	Point2 operator * (double k)
	{
		return Point2(k*x, k*y);
	}
	
	Point2 normalize()
	{
		return (*this) * (1/length());
	}
	
	Point2 operator + (Point2 other)
	{
		return Point2(x+other.x, y+other.y);
	}
	
	Point2 operator - (Point2 other)
	{
		return Point2(x-other.x, y-other.y);
	}
	
	double dist(Point2 other)
	{
		return (*this-other).length();
	}
	
	double operator ^ (Point2 other)
	{
		return x*other.x + y*other.y;
	}
	
	double operator * (Point2 other)
	{
		return x*other.y - y*other.x;
	}
	
	void display()
	{
		printf("Point2 (%lf , %lf)\n",x,y);
	}
};

Point2 operator * (double k,Point2 p)
{
	return Point2(k*p.x, k*p.y);
}


struct Plane
{
	double a,b,c,d;
	Point3 A,B,C;
	Point3 N,O,X,Y;
	
	Plane() {}
	
	Plane(Point3 _AA, Point3 _BB, Point3 _CC)
	{
		A=_AA;
		B=_BB;
		C=_CC;
		
		Point3 normal = (B-A)*(C-A);
		N = normal.normalize();
		
		a = N.x;
		b = N.y;
		c = N.z;
		d = -(A^N);
		
		O = Point3(-d*a, -d*b, -d*c);
		if(A!=O) 	X = (A-O).normalize();
		else 		X = (B-O).normalize();
		Y = normal*X;
	}
	
	Plane(double _a,double _b,double _c,double _d)
	{
		double len = sqrt(_a*_a + _b*_b + _c*_c);
		a = _a/len;
		b = _b/len;
		c = _c/len;
		d = _d/len;
		N=Point3(a,b,c);
		
		if(a!=0)
		{
			A = Point3(-(d+0*b+0*c)/a,0,0);
			B = Point3(-(d+1*b+0*c)/a,1,0);
			C = Point3(-(d+0*b+1*c)/a,0,1);
		}
		else if(b!=0)
		{
			A = Point3(0,-(d+0*a+0*c)/b,0);
			B = Point3(1,-(d+1*a+0*c)/b,0);
			C = Point3(0,-(d+0*a+1*c)/b,1);
		}
		else
		{
			A = Point3(0,0,-(d+0*a+0*b)/c);
			B = Point3(1,0,-(d+1*a+0*b)/c);
			C = Point3(0,1,-(d+0*a+1*b)/c);
		}
		
		O = Point3(-d*a, -d*b, -d*c);
		if(A!=O) 	X = (A-O).normalize();
		else 		X = (B-O).normalize();
		Y = N*X;
	}
	
	Point3 project(Point3 P)
	{
		return (P-(P^N)*N) + O;
	}
	
	Point2 project2D(Point3 P)
	{
		P = project(P);
		return Point2(P^X,P^Y);
	}
	
	double distance(Point3 p)
	{
		return abs(a*p.x + b*p.y + c*p.z + d);
	}
	
	void display()
	{
		printf("Plane (%lf , %lf , %lf , %lf)\n",a,b,c,d);
		printf("A : "); A.display();
		printf("B : "); B.display();
		printf("C : "); C.display();
		printf("N : "); N.display();
		printf("O : "); O.display();
		printf("X : "); X.display();
		printf("Y : "); Y.display();
	}
		
};
		
		
		
		
	
	
	

void preprocess()
{

}


int n,m;
vector<Point3> p3;
vector<Point2> p2;
vector<Plane> plns;

double eval(double x,double y)
{
	double ans=0;
	double dx,dy;
	for(int i=0;i<n;i++)
	{
		dx = x-p2[i].x;
		dy = y-p2[i].y;
		ans = max(ans, dx*dx + dy*dy);
	}
	return ans;
}

pair<double,double> doTernaryY(double x)
{
	double lo = 1e4;
	double hi = 0;
	for(int i=0;i<n;i++)
	{
		lo=min(lo,p2[i].y);
		hi=max(hi,p2[i].y);
	}
	
	for(int iter=0;iter<35;iter++)
	{
		double y1 = (lo+lo+hi)/3;
		double y2 = (lo+hi+hi)/3;
		
		double val1 = eval(x,y1);
		double val2 = eval(x,y2);
		
		if(val1<val2)
			hi = y2;
		else
			lo = y1;
	}
	
	double ans = (lo+hi)/2;
	return mp(ans,eval(x,ans));
}

pair<double,double> doTernaryX()
{
	double lo = 1e4;
	double hi = 0;
	for(int i=0;i<n;i++)
	{
		lo=min(lo,p2[i].x);
		hi=max(hi,p2[i].x);
	}
	
	for(int iter=0;iter<35;iter++)
	{
		double x1 = (lo+lo+hi)/3;
		double x2 = (lo+hi+hi)/3;
		
		double val1 = doTernaryY(x1).second;
		double val2 = doTernaryY(x2).second;
		
		if(val1<val2)
			hi = x2;
		else
			lo = x1;
	}
	
	double ans = (lo+hi)/2;
	return mp(ans,doTernaryY(ans).first);
}


void solve()
{
	p2.resize(n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			p2[j] = plns[i].project2D(p3[j]);
			
		pair<double,double> centre = doTernaryX();
		double rad = sqrt(eval(centre.first, centre.second));
		printf("%.9lf\n",rad);
	}
}

bool input()
{
	s(n); s(m);
	p3.resize(n);
	plns.resize(m);
	
	int a,b,c;
	for(int i=0;i<n;i++)
	{
		s(a); s(b); s(c);
		p3[i] = Point3(a,b,c);
	}
	
	for(int i=0;i<m;i++)
	{
		s(a); s(b); s(c);
		plns[i] = Plane(a,b,c,0);
	}
	
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}