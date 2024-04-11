#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(Point<long long> p) {return "("+ts(p.x)+", "+ts(p.y)+")"; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif



int escapes[3001][3001];
double angg[3001][3001];

const double pi = 2*acos(0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    long long R;
    cin >> n >> R;

    vector<Point<long long>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) angg[i][j] = (p[i] - p[j]).angle();
    }

    for (int i = 0; i < n; i++) {
        vector< pair<double, pair<int, int> > > events;

        int cnt = 0;
        int req = 0;

        for (int j = 0; j < n; j++) if (j != i) {
            double ang = angg[j][i];
            if (j < i) events.push_back({ang, {j, 0}});

            if ( (p[j] - p[i]).dist2() > R*R) {
                req++;
                if (ang - pi/2 < -pi - 1e-6) {
                    cnt++;
                    events.push_back({ ang + 3*pi/2, {j, 1}});
                }
                else events.push_back({ang - pi/2, {j, 1}});
                if (ang + pi/2 < pi + 1e-6) events.push_back({ ang + pi/2, {j, -1}});
                else {
                    cnt++;
                    events.push_back({ ang - 3*pi/2, {j, -1}});
                }
            }
        }

        sort(all(events));
        int lat = -1;

        for (int _ = 0; _ < events.size(); _++) {
            int idx = events[_].second.first;
            int typ = events[_].second.second;

            if (typ == 0) {
                escapes[i][idx] = (cnt != req);
            }
            else cnt += typ;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {

        double lowL = -pi, lowR = -pi, highL = pi, highR = pi;

        for (int j = 0; j < n; j++) if (j != i) {
            double ang = angg[j][i];

            long long dist2 = (p[j] - p[i]).dist2();
            if (dist2 <= R*R) {
                continue;
            }

            double theta = asin( R / sqrt((double)dist2) );
            if (ang - theta < -pi - 1e-6) {
                highL = min(highL, ang+theta);
                lowR = max(lowR, ang - theta + 2*pi);
            }
            else if (ang + theta > pi + 1e-6) {
                highL = min(highL, ang + theta - 2*pi);
                lowR = max(lowR, ang - theta);
            }
            else {
                highL = min(highL, ang+theta);
                highR = min(highR, ang+theta);
                lowL = max(lowL, ang-theta);
                lowR = max(lowR, ang-theta);
            }
        }

        for (int idx = i+1; idx < n; idx++) if (!escapes[idx][i]) {
            if (lowL - 1e-6 < angg[idx][i] && angg[idx][i] < highL + 1e-6) ans++;
            else if (lowR - 1e-6 < angg[idx][i] && angg[idx][i] < highR + 1e-6) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}