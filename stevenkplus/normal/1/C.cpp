/*
 PROG: tseat
 LANG: C++
 ID: li.ray.1
 #yolo
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <fstream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
const int inf = 1 << 30;
const ll infl = 1ll << 60;
char buf[1000000];
string nextLine() {
	scanf("%[^\n]", buf);
	getc(stdin);
	string s(buf);
	return s;
}
string next() {
	scanf("%s", buf);
	return string(buf);
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}
const int MAXN = 110;
int ans[MAXN][MAXN];
pii s;
ll d(pii a, pii b) {
	int dx = a.fi - b.fi;
	int dy = a.se - b.se;
	return dx * dx + dy * dy;
}
bool comp(pii a, pii b) {
	ll da = d(a, s);
	ll db = d(b, s);
	if (da == db) {
		if (a.fi == b.fi) {
			return a.se < b.se;
		}
		return a.fi < b.fi;
	}
	return da < db;
}
typedef pair<double, double> point;
double dist(point A, point B) {
	return hypot(A.fi - B.fi, A.se - B.se);
}
point add(point a, point b) {
	return point(a.fi + b.fi, a.se + b.se);
}
point mult(point a, double scal) {
	return point(a.fi * scal, a.se * scal);
}
point circumcenter(point A, point B, point C) {
	double a = dist(B, C), b = dist(C, A), c = dist(A, B);
	double as = a * a, bs = b * b, cs = c * c;
	double baryA = as * (bs + cs - as), baryB = bs * (as + cs - bs), baryC = cs
			* (as + bs - cs);
	double barySum = baryA + baryB + baryC;
	point end = add(add(mult(A, baryA / barySum), mult(B, baryB / barySum)),
			mult(C, baryC / barySum));
	return end;
}
const double rev = 2 * M_PI;
double ang(point a, point b) {
	double r = atan2(b.se - a.se, b.fi - a.fi);
	if (r < 0)
		return r + rev;
	return r;
}
double eps = 1E-5;

bool isrev(double k) {
	double p = k / rev;
	return abs(p - round(p)) < eps;
}
int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}
int main() {
	if (fopen("tseat.in", "r")) {
		freopen("tseat.in", "r", stdin);
		freopen("tseat.out", "w", stdout);
	}
	double a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	point A = point(a, b), B = point(c, d), C = point(e, f);
	point circ = circumcenter(A, B, C);
//	p(circ.fi);
//	p(circ.se);

	double t1 = ang(circ, A), t2 = ang(circ, B), t3 = ang(circ, C);
	t2 -= t1;
	t3 -= t1;
	if (t2 < 0)
		t2 += rev;
	if (t3 < 0)
		t3 += rev;
	int nsides;
	for (nsides = 3; nsides < 100; nsides++) {
		if (isrev(nsides * t2) && isrev(nsides * t3))
			break;
	}
	double rad = dist(circ, A);
	double area = nsides * (rad * rad * sin(rev / nsides) / 2);
	printf("%.10f\n", area);
}