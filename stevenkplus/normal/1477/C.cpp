// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
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

// ============= Solution ============= //
int main() { // dobby is a free elf
   using pt = Point<ll>;
   auto ok = [&](pt a, pt b, pt c) -> bool {
      return (a - b).dot(c - b) > 0;
   };

   int n;
   cin >> n;
   vector<int> x(n), y(n);
   for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
   }
   vector<pt> v(n);
   for (int i = 0; i < n; ++i) v[i] = pt(x[i], y[i]);
   vector<int> ans(n);
   for (int i = 0; i < n; ++i) ans[i] = i;
   for (int i = 2; i < n; ++i) {
      for (int j = i; j >= 2; --j) {
         if (ok(v[j - 2], v[j - 1], v[j])) {
            break;
         }
         swap(v[j], v[j - 1]);
         swap(ans[j], ans[j - 1]);
      }
   }

   for (int i: ans) cout << i + 1 << " ";
   cout << "\n";

}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases