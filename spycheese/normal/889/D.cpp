#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 2111;

struct Vec2
{
	ll x, y;
	
	Vec2() {}
	Vec2(ll nx, ll ny) : x(nx), y(ny) {}

	Vec2 operator + (const Vec2 & b) const { return { x+b.x, y+b.y }; }
	Vec2 operator - (const Vec2 & b) const { return { x-b.x, y-b.y }; }
	Vec2 operator - () const { return { -x, -y }; }
	Vec2 operator * (ll b) const { return { x*b, y*b }; }

	Vec2 & operator += (const Vec2 & b) { x+=b.x; y+=b.y; return *this; }
	Vec2 & operator -= (const Vec2 & b) { x-=b.x; y-=b.y; return *this; }
	Vec2 & operator *= (ll b) { x*=b; y*=b; return *this; }

	bool operator == (const Vec2 & b) const { return x==b.x && y==b.y; }
	bool operator != (const Vec2 & b) const { return x!=b.x && y!=b.y; }
	bool operator <  (const Vec2 & b) const { return x==b.x ? y<b.y : x<b.x; }
	bool operator <= (const Vec2 & b) const { return x==b.x ? y<=b.y : x<b.x; }
	bool operator >  (const Vec2 & b) const { return x==b.x ? y>b.y : x>b.x; }
	bool operator >= (const Vec2 & b) const { return x==b.x ? y>=b.y : x>b.x; }
};

istream & operator >> (istream & in, Vec2 & v) { return in >> v.x >> v.y; }
ostream & operator << (ostream & out, const Vec2 & v) { return out << v.x << " " << v.y; }
Vec2 operator * (ll b, const Vec2 & a) { return { b*a.x, b*a.y }; }
ll dot(const Vec2 & a, const Vec2 & b) { return a.x*b.x + a.y*b.y; }
ll cross(const Vec2 & a, const Vec2 & b) { return a.x*b.y - a.y*b.x; }
ll length2(const Vec2 & a) { return a.x*a.x + a.y*a.y; }
double length(const Vec2 & a) { return sqrt(a.x*a.x + a.y*a.y); }

int n;
Vec2 p[N];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    Vec2 psum = {0, 0};
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        psum += p[i];
        p[i] *= n;
    }
    for (int i = 0; i < n; ++i)
        p[i] -= psum;

    set<Vec2> ps;
    for (int i = 0; i < n; ++i) {
        if (p[i] == Vec2(0,0))
            continue;
        if (ps.count(-p[i]))
            ps.erase(-p[i]);
        else
            ps.insert(p[i]);
    }

    if (ps.empty()) {
        cout << "-1\n";
        return 0;
    }

    n = 0;
    for (Vec2 x : ps)
        p[n++] = x;

    vector<Vec2> ans;
    for (int ii = 0; ii < n; ++ii) {
        Vec2 v = (p[0] + p[ii]);
        bool ok = true;
        for (Vec2 v1 : ans)
            if (cross(v1, v) == 0) {
                ok = false;
                break;
            }
        if (!ok)
            continue;
        vector<ll> xx;
        for (int i = 0; i < n; ++i)
            xx.push_back(cross(p[i], v));
        sort(ALL(xx));
        ok = 1;
        for (int i = 0; i < n; ++i)
            if (xx[i] != -xx[n-1-i]) {
                ok = false;
                break;
            }
        if (ok)
            ans.push_back(v);
    }

    cout << sz(ans) << "\n";

    return 0;
}