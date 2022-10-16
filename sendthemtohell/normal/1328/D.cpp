#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,tune=native")
#endif //LOCAL

#define _SCL_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:256000000")

//#define push_back pb
#define first x
#define second y

#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <memory>
#include <chrono>

#ifdef LOCAL
//#include <vld.h>
#endif //LOCAL
using namespace std;

//typedef __int128_t ll;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;

#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false)
#define coutdouble cout<<setprecision(20);cout<<fixed

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

#ifdef LOCAL
mt19937 rd(57322);
#else
mt19937 rd((uint)chrono::steady_clock::now().time_since_epoch().count());
#endif
/*------CommentInInteractive--------*/
#ifndef LOCAL
#define endl '\n'
#endif //LOCAL
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
constexpr uint MOD = 1000 * 1000 * 1000 + 7;
constexpr uint FFT_MOD = 998244353;
const int P1E6 = 1336337;
const int P1E3 = 1009;
const ll P1E14 = 100000000000031;
const ll P1E17 = 100000000000000003;
const ld PI = acosl(-1.);//3.1415926535897932384626433832795
const ld EPS = 1e-9;
/*------------------------------------------------IO_OPERATORS---------------------------------------------*/
template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << " " << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
/*--------------------------------------------------IO_FILES-----------------------------------------------*/
const char * infile =
#ifdef LOCAL
"input.txt"
#else
""
#endif //LOCAL
;
const char * outfile =
#ifdef LOCAL
""
#else
""
#endif //LOCAL
;

/*-------------------------------------------------ALLOCATOR----------------------------------------------*/
//#define ALLOC_LOCAL
#ifdef ALLOC_LOCAL
const int ML_ = 450;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false);  _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD) { if (pow < 0) { pow = pow % (MD - 1) + MD - 1; } ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }
inline ll gcdex(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; } ll xx, yy; ll gc = gcdex(b, a % b, yy, xx); x = xx; y = yy - (a / b) * xx; return gc; }
inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }
/*-----------------------------------------------------CODE------------------------------------------------*/

struct Point {
	double x, y, z;
	Point() : x(0), y(0), z(0) {}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point operator*(const Point & p) const
	{
		return
			Point
			(
				y * p.z - z * p.y,
				z * p.x - x * p.z,
				x * p.y - y * p.x
			);
	}
	Point rotate(Point normal) const 
	{
		Point v = *this;
		return v * normal;
	}
};

ld dst(pair<ld, ld>& p1, pair<ld, ld>& p2) {
	return hypotl(p1.x - p2.x, p1.y - p2.y);
}

void slv() {

	ld xs, ys, zs;
	cin >> xs >> ys >> zs;

	ld xd, yd, zd;
	cin >> xd >> yd >> zd;

	ld r;
	cin >> r;

	ld a, b, c, d;
	cin >> a >> b >> c >> d;
	d = -d;

	if (a != 0) {
		// x -= d / a
		xs -= d / a;
		xd -= d / a;
	} else if (b != 0) {
		ys -= d / b;
		yd -= d / b;
	} else if (c != 0) {
		zs -= d / c;
		zd -= d / c;
	} else {
		assert(false);
	}

	if (b != 0 || a != 0) {
		ld oox = b, ooy = -a, ooz = 0;
		ld oor = sqrtl(oox * oox + ooy * ooy + ooz * ooz);
		assert(abs(oox * a + ooy * b + ooz * c) < EPS);

		ld ox, oy, oz;
		if (c == 0) {
			oz = 1;
			ox = 0;
			oy = 0;
		} else {
			ox = a;
			oy = b;
			oz = (-a * a - b * b) / c;
		}
		ld or1 = sqrtl(ox * ox + oy * oy + oz * oz);
		assert(abs(ox * a + oy * b + oz * c) < EPS);
		assert(abs(ox * oox + oy * ooy + oz * ooz) < EPS);


		ld cs = oox / sqrtl(a * a + b * b);
		ld sn = -ooy / sqrtl(a * a + b * b);

		ld tx, ty;
		tx = cs * xs - sn * ys;
		ty = sn * xs + cs * ys;

		xs = tx;
		ys = ty;

		tx = cs * xd - sn * yd;
		ty = sn * xd + cs * yd;

		xd = tx;
		yd = ty;
		
		tx = cs * ox - sn * oy;
		ty = sn * ox + cs * oy;

		ox = tx;
		oy = ty;

		tx = cs * oox - sn * ooy;
		ty = sn * oox + cs * ooy;

		oox = tx;
		ooy = ty;

		assert(abs(ox) < EPS);
		assert(abs(ooy) < EPS && abs(ooz) < EPS);

		// (0, oy, oz) -> (0, .., 0)
		sn = -oz / sqrtl(oz * oz + oy * oy);
		cs = oy / sqrtl(oz * oz + oy * oy);

		tx = cs * ys - sn * zs;
		ty = sn * ys + cs * zs;

		ys = tx;
		zs = ty;

		tx = cs * yd - sn * zd;
		ty = sn * yd + cs * zd;

		yd = tx;
		zd = ty;

		tx = cs * oy - sn * oz;
		ty = sn * oy + cs * oz;

		oy = tx;
		oz = ty;

		tx = cs * ooy - sn * ooz;
		ty = sn * ooy + cs * ooz;

		ooy = tx;
		ooz = ty;

		assert(abs(ooy) < EPS && abs(ooz) < EPS);
		assert(abs(ox) < EPS && abs(oz) < EPS);
		assert(abs(oox * oox - oor * oor) < EPS && abs(oy * oy - or1 * or1) < EPS);
	}

	d = sqrtl((xs - xd) * (xs - xd) + (ys - yd) * (ys - yd) + (zs - zd) * (zs - zd));
	ld sn = r / d;
	ld mv = r * sn / d;

	ld dx = (xs - xd) * mv;
	ld dy = (ys - yd) * mv;
	ld dz = (zs - zd) * mv;

	ld ourr = sqrtl(r * r - dx * dx - dy * dy - dz * dz);

	ld vx, vy, vz;
	if (abs(dx) > EPS || abs(dy) > EPS) {
		vx = dy / sqrtl(dy * dy + dx * dx);
		vy = -dx / sqrtl(dy * dy + dx * dx);
		vz = 0;
		vx *= ourr;
		vy *= ourr;
	} else {
		vx = ourr;
		vy = 0;
		vz = 0;
	}
	assert(abs(vx * vx + vy * vy + vz * vz - ourr * ourr) < EPS);
	assert(abs(vx * dx + vy * dy + vz * dz) < EPS);
	//cout << dx << " " << dy << " " << dz << endl;
	//cout << vx << " " << vy << " " << vz << endl;
	//cerr << xs << " " << ys << " " << zs << endl;
	//cerr << xd << " " << yd << " " << zd << endl;
	//cerr << r << endl;


	vector<pair<ld, ld>> pt;
	ld lul = sqrtl(dx * dx + dy * dy + dz * dz);
	dx /= lul;
	dy /= lul;
	dz /= lul;
	assert(abs(dx * dx + dy * dy + dz * dz - 1) < EPS);
	vector<ld> rrr;
	for (int i = 0; i < 4; ++i) {
		ld rx = xd + dx * lul + vx;
		ld ry = yd + dy * lul + vy;
		ld rz = zd + dz * lul + vz;

		{
			ld chx = rx - xd;
			ld chy = ry - yd;
			ld chz = rz - zd;

			assert(abs(sqrtl(chx * chx + chy * chy + chz * chz) - r) < EPS);
		}

		ld cf = zs / rz;

		ld x = (cf * rx - xs) / (cf - 1);
		ld y = (cf * ry - ys) / (cf - 1);
		ld z = 0;

		pt.push_back({ x, y });

		{
			ld a1 = rx - x;
			ld a2 = xs - x;
			ld b1 = ry - y;
			ld b2 = ys - y;
			ld c1 = rz - z;
			ld c2 = zs - z;
			ld cff = c2 / c1;

			assert(abs(cff - cf) < EPS);
			assert(abs(a1 * cf - a2) < EPS);
			assert(abs(a1 * cf - a2) < EPS);
			assert(abs(c1 * cf - c2) < EPS);
		}
		rrr.push_back(1 / cf);

		Point p(vx, vy, vz);
		p = p.rotate(Point(dx, dy, dz));
		vx = p.x;
		vy = p.y;
		vz = p.z;
	}

	pair<ld, ld> d2 = { pt[3].x - pt[1].x, pt[3].y - pt[1].y };
	
	ld aa = hypotl(d2.x, d2.y);
	pair<ld, ld> mid = { pt[1].x + pt[3].x, pt[1].y + pt[3].y };
	mid.x /= 2;
	mid.y /= 2;
	ld bb = 0;

	ld nx = xs - mid.x;
	ld ny = ys - mid.y;
	ld nz = zs;
	ld al = 1 - rrr[1];
	ld bt = 1 - rrr[3];
	
	ld cff = 2 * al * bt / (al + bt);
	nx *= cff;
	ny *= cff;
	nz *= cff;

	nx += mid.x;
	ny += mid.y;

	{
		vx = dy / sqrtl(dy * dy + dx * dx);
		vy = -dx / sqrtl(dy * dy + dx * dx);
		vz = 0;
		
		ld rem = sqrtl(r * r - (nx - xd) * (nx - xd) - (ny - yd) * (ny - yd) - (nz - zd) * (nz - zd));

		vx *= rem;
		vy *= rem;

		vector<pair<ld, ld>> pt2;
		for (int i = 0; i < 2; ++i) {
			ld rx = nx + vx;
			ld ry = ny + vy;
			ld rz = nz + vz;

			ld cf = zs / rz;

			ld x = (cf * rx - xs) / (cf - 1);
			ld y = (cf * ry - ys) / (cf - 1);
			ld z = 0;

			pt2.push_back({ x, y });

			vx = -vx;
			vy = -vy;
		}
		bb = hypotl(pt2[1].x - pt2[0].x, pt2[1].y - pt2[0].y);
	}

	cout << PI * aa * bb / 2 << endl;
}

inline void solve() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);
		cin >> v;

		int sw = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i] != v[(i + 1) % n]) {
				++sw;
			}
		}
		if (sw == 0) {
			cout << 1 << endl;
			cout << vector<int>(n, 1) << endl;
			continue;
		}
		if (sw != n || (n & 1) == 0) {
			cout << 2 << endl;
			cout << 1 << " ";
			int cur = 0;
			if (sw & 1) {
				bool was = false;
				for (int i = 1; i < n; ++i) {
					if (v[i] != v[i - 1]) {
						cur ^= 1;
					}
					else if (!was) {
						was = true;
						cur ^= 1;
					}
					cout << cur + 1 << " ";
				}
			}
			else {
				for (int i = 1; i < n; ++i) {
					if (v[i] != v[i - 1]) {
						cur ^= 1;
					}
					cout << cur + 1 << " ";
				}
			}
			cout << endl;
			continue;
		}
		cout << 3 << endl;
		for (int i = 0; i + 1 < n; ++i) {
			if (i & 1) {
				cout << 2 << " ";
			} else {
				cout << 1 << " ";
			}
		}
		cout << 3 << endl;
	}

}

int main() {

	if (*infile != '\0')
		(void)freopen(infile, "r", stdin);
	if (*outfile != '\0')
		(void)freopen(outfile, "w", stdout);

	speedup;
	coutdouble;


	//int tst = 1;
	//srand(time(NULL));
	//cin >> tst;
	//scanf("%d", &tst);
	//while (tst-- > 0) {
	//while (true) {
	solve();
	//if ((tst & 0xF) == 0) {
	//cerr << "ok\n";
	//}
	//cerr << "/*-----------------*/\n";
	//}

#ifdef LOCAL
	cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL

	return 0;
}