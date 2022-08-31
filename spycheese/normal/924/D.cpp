#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

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
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 100179;

typedef long long ll;

struct Vec2 {
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
	bool operator != (const Vec2 & b) const { return x!=b.x || y!=b.y; }
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

bool operator < (lpair const& a, lpair const& b) {
    return (ll)a.X * b.Y < (ll)a.Y * b.X;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll w;
    cin >> n >> w;
    vector<Vec2> ps(n), vs(n);
    for (int i = 0; i < n; ++i) {
        ll x, v;
        cin >> x >> v;
        ps[i] = {x, 0};
        vs[i] = {v, 1};
    }

    Vec2 w1 = {-w, 1};
    Vec2 w2 = {w, 1};

    vector<lpair> c1, c2;
    for (int i = 0; i < n; ++i) {
        ll t1 = cross(ps[i], vs[i]);
        ll t2 = cross(w1, vs[i]);
        if (t2 < 0) {
            t1 = -t1;
            t2 = -t2;
        }
        ll g = __gcd(t1, t2);
        t1 /= g;
        t2 /= g;
        c1.push_back({t1, t2});
    }

    for (int i = 0; i < n; ++i) {
        ll t1 = cross(ps[i], vs[i]);
        ll t2 = cross(w2, vs[i]);
        if (t2 < 0) {
            t1 = -t1;
            t2 = -t2;
        }
        ll g = __gcd(t1, t2);
        t1 /= g;
        t2 /= g;
        c2.push_back({t1, t2});
    }

    vector<int> order1(n);
    iota(all(order1), 0);
    sort(all(order1), [&](int q1, int q2) {
        if (c1[q1] == c1[q2])
            return c2[q2] < c2[q1];
        return c1[q1] < c1[q2];
    });

    if (w == 0) {
        ll ans = 0;
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && c1[order1[i]] == c1[order1[j]])
                ++j;
            ans += (j - i) * (j - i - 1LL) / 2;
            i = j;
        }
        cout << ans << "\n";
        return 0;
    }


    vector<int> order2(n);
    iota(all(order2), 0);
    sort(all(order2), [&](int q1, int q2) {
        if (c2[q1] == c2[q2])
            return c1[q2] < c1[q1];
        return c2[q1] < c2[q2];
    });

    vector<int> perm(n);

    auto inv = [](vector<int> const& a) {
        vector<int> b(sz(a));
        for (int i = 0; i < sz(a); ++i)
            b[a[i]] = i;
        return b;
    };
    order1 = inv(order1);
    order2 = inv(order2);
    for (int i = 0; i < n; ++i)
        perm[order1[i]] = order2[i];

    ll ans = 0;
    struct Fen {
        vector<int> t;
        Fen(int n) : t(n + 5) {}
        void inc(int x) {
            for (; x < sz(t); x |= x + 1)
                ++t[x];
        }
        int sum(int x) {
            int s = 0;
            for (--x; x >= 0; x = (x&(x+1))-1)
                s += t[x];
            return s;
        }
    } fen(n);

    for (int i = n - 1; i >= 0; --i) {
        ans += fen.sum(perm[i]);
        fen.inc(perm[i]);
    }

    cout << ans << "\n";

    return 0;
}