#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

const int N = 1179;

struct Vec2
{
	double x, y;
	
	Vec2() {}
	Vec2(double nx, double ny) : x(nx), y(ny) {}

	Vec2 operator + (const Vec2 & b) const { return { x+b.x, y+b.y }; }
	Vec2 operator - (const Vec2 & b) const { return { x-b.x, y-b.y }; }
	Vec2 operator - () const { return { -x, -y }; }
	Vec2 operator * (double b) const { return { x*b, y*b }; }
	Vec2 operator / (double b) const { return { x/b, y/b }; }

	Vec2 & operator += (const Vec2 & b) { x+=b.x; y+=b.y; return *this; }
	Vec2 & operator -= (const Vec2 & b) { x-=b.x; y-=b.y; return *this; }
	Vec2 & operator *= (double b) { x*=b; y*=b; return *this; }
	Vec2 & operator /= (double b) { x/=b; y/=b; return *this; }

	bool operator == (const Vec2 & b) const { return x==b.x && y==b.y; }
	bool operator != (const Vec2 & b) const { return x!=b.x && y!=b.y; }
	bool operator <  (const Vec2 & b) const { return x==b.x ? y<b.y : x<b.x; }
	bool operator <= (const Vec2 & b) const { return x==b.x ? y<=b.y : x<b.x; }
	bool operator >  (const Vec2 & b) const { return x==b.x ? y>b.y : x>b.x; }
	bool operator >= (const Vec2 & b) const { return x==b.x ? y>=b.y : x>b.x; }
};

Vec2 operator * (double b, const Vec2 & a) { return { b*a.x, b*a.y }; }
double dot(const Vec2 & a, const Vec2 & b) { return a.x*b.x + a.y*b.y; }
double cross(const Vec2 & a, const Vec2 & b) { return a.x*b.y - a.y*b.x; }
double length2(const Vec2 & a) { return a.x*a.x + a.y*a.y; }
double length(const Vec2 & a) { return sqrt(a.x*a.x + a.y*a.y); }
Vec2 normalize(const Vec2 & a) { return a / sqrt(a.x*a.x + a.y*a.y); }
Vec2 rotate(const Vec2 & a, double b) { double c = cos(b), s = sin(b); return { a.x*c-a.y*s, a.y*c+a.x*s }; }

int n;
Vec2 p[N];

double check()
{
	double ans = DINF;
	for (int i = 0; i < n; ++i)
	{
		Vec2 p1 = p[i];
		Vec2 p2 = p[(i+1)%n];
		Vec2 p3 = p[(i+2)%n];
		Vec2 v = p3 - p1;
		double dist = abs(cross(v, p2 - p1)) / length(v);
		ans = min(ans, dist / 2.0);
	}
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	
	double r = check();
	for (int i = 0; i < n; ++i)
		r = min(r, length(p[i] - p[(i + 1) % n]) / 2.0);

	cout.precision(20);
	cout << r << "\n";

    return 0;
}