#define _ijps 0
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;

#define name ""
typedef unsigned long long ull;
typedef long long ll;
#define mk make_pair
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

struct __isoff{
	__isoff(){
		if (_ijps)
			freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
		//else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
		//ios_base::sync_with_stdio(0);
		//srand(time(0));
		srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
	}
	~__isoff(){
		//if(_ijps) cout<<times<<'\n';
	}
} __osafwf;
//const ull p1 = 131;
//const ull p2 = 129;
const double eps = 1e-7;
const double pi = acos(-1.0);

const int infi = 1e9 + 7;
const ll inf = 1e18 + 7;
const ll dd = 1e5 + 7;
const ll mod = 1e9 + 7;

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-8;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 100179;

struct Vec3
{
	double x, y, z;

	Vec3(){}
	Vec3(double nx, double ny, double nz) : x(nx), y(ny), z(nz) {}

	Vec3 operator + (const Vec3 & b) const { return Vec3(x+b.x, y+b.y, z+b.z); }
	Vec3 & operator += (const Vec3 & b) { x += b.x; y += b.y; z += b.z; return *this; }
	Vec3 operator - (const Vec3 & b) const { return Vec3(x-b.x, y-b.y, z-b.z); }
	Vec3 operator * (double b) const { return Vec3(x*b, y*b, z*b); }
	Vec3 operator / (double b) const { return Vec3(x/b, y/b, z/b); }
};

double dot(const Vec3 & a, const Vec3 & b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec3 cross(const Vec3 & a, const Vec3 & b)
{
	return Vec3(a.y*b.z-a.z*b.y,
				a.z*b.x-a.x*b.z,
				a.x*b.y-a.y*b.x);
}

double length2(const Vec3 & a)
{
	return a.x*a.x + a.y*a.y + a.z*a.z;
}

double length(const Vec3 & a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

Vec3 normalize(const Vec3 & a)
{
	return a / length(a);
}

struct Vec2
{
	double x, y;

	Vec2(){}
	Vec2(double nx, double ny) : x(nx), y(ny) {}

	Vec2 operator + (const Vec2 & b) const { return Vec2(x+b.x, y+b.y); }
	Vec2 operator - (const Vec2 & b) const { return Vec2(x-b.x, y-b.y); }
	Vec2 operator * (double b) const { return Vec2(x*b, y*b); }
	Vec2 operator / (double b) const { return Vec2(x/b, y/b); }
	bool operator < (Vec2 b) const{
		return x < b.x;
	}
};

double dot(const Vec2 & a, const Vec2 & b)
{
	return a.x*b.x + a.y*b.y;
}

double cross(const Vec2 & a, const Vec2 & b)
{
	return a.x*b.y - a.y*b.x;
}

double length2(const Vec2 & a)
{
	return a.x*a.x + a.y*a.y;
}

double length(const Vec2 & a)
{
	return sqrt(a.x*a.x + a.y*a.y);
}

Vec2 normalize(const Vec2 & a)
{
	return a / length(a);
}

int n1, n2;
Vec3 p1[N], p2[N];
Vec3 basisX, basisY, basisZ;
vector < pair < Vec3, int > > its3;

Vec2 a[N];
vector < pair < Vec2, int > > its;

double D;

struct seg{
	Vec2 a, b;
	int num;
	bool type;
	bool ispoint = 0;
	seg(Vec2 A, Vec2 B, int num) : a(A), b(B), num(num){
		if(b < a){
			type = 1;
			swap(a, b);
		}
	}
	seg(){
		num = -1;
	}
	double get(double x) const{
		if(ispoint){
			return a.y;
		}
		double l = (x - a.x) / (b.x - a.x);
		return l * (b.y - a.y) + a.y;
	}

	bool operator < (seg b) const{
		double a = get(D);
		double c = b.get(D);
		if(abs(a - c) < eps){
			return num < b.num;
		}
		return a < c;
	}
};

struct qu{
	seg A;
	int type;
	Vec2 B;
	double x;
	int S = 0;
	qu(){

	}
	bool operator < (qu b) const{
		return x < b.x;
	}
};

set<seg> T;

int main(){
 ios::sync_with_stdio(false);

	scanf("%d", &n1);
	for (int i = 0; i < n1; ++i)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		p1[i].x = x;
		p1[i].y = y;
		p1[i].z = z;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; ++i)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		p2[i].x = x;
		p2[i].y = y;
		p2[i].z = z;
	}
	
	basisX = normalize(p1[1] - p1[0]);
	basisZ = normalize(cross(basisX, p1[n1 - 1] - p1[0]));
	basisY = cross(basisZ, basisX);

	for (int i = 0; i < n2; ++i)
	{
		Vec3 a = p2[i], b = p2[i + 1 == n2 ? 0 : i + 1];
		double adist = dot(a - p1[0], basisZ);
		double bdist = dot(b - p1[0], basisZ);
		if ((adist > EPS) != (bdist > EPS))
		{
			Vec3 p = a + (b - a) * (abs(adist) / (abs(adist) + abs(bdist)));
			its3.emplace_back(p, (adist > EPS ? 1 : -1));
		}
	}

	for (int i = 0; i < n1; ++i)
		a[i] = Vec2(dot(basisX, p1[i]), dot(basisY, p1[i]));
	for (auto pp : its3)
		its.emplace_back(Vec2(dot(basisX, pp.X), dot(basisY, pp.X)), pp.Y);
	
	if (sz(its) == 0)
	{
		cout << "NO\n";
		return 0;
	}
	Vec2 lp = its[0].X, ld = Vec2(1.0, 0.0);
	for (int i = 1; i < sz(its); ++i)
		if (length2(its[i].X - lp) > EPS)
		{
			ld = normalize(its[i].X - lp);
			break;
		}
	Vec2 ln = Vec2(-ld.y, ld.x);
	
	vector < pair < double , int > > its1;
	for (auto pp : its)
		its1.emplace_back(dot(pp.X - lp, ld), pp.Y);
	for (int i = 0; i < n1; ++i)
	{
		Vec2 q = a[i], w = a[i + 1 == n1 ? 0 : i + 1];
		double qdist = dot(q - lp, ln);
		double wdist = dot(w - lp, ln);
		if ((wdist > EPS) != (qdist > EPS))
		{
			Vec2 pp = q + (w - q) * (abs(qdist) / (abs(qdist) + abs(wdist)));
			its1.emplace_back(dot(pp - lp, ld), 0);
		}
	}

	sort(its1.begin(), its1.end());
	int res = 0;
	bool ins = false;
	for (auto pp : its1)
		if (pp.Y == 0)
			ins ^= true;
		else if (ins)
			res += pp.Y;
	cout << (res == 0 ? "NO\n" : "YES\n");
	

    return 0;
}