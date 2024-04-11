#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { out << "["; forn(i, sz(a)) { if (i) out << ','; out << ' ' << a[i]; } return out << " ]"; }
template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }
 
inline ld gett() { return clock() / ld(CLOCKS_PER_SEC); }
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
const int N = 500500, L = 111;
 
int n;
string a[N];
 
bool read() {
    if (!(cin >> n)) return false;
    forn(i, n) {
        cin >> a[i];
    }
    return true;
}
 
inline bool cmp(const string& a, const string& b) {
    return a + b < b + a;
}
 
void solve() {
    sort(a, a + n, cmp);
string ans;
ans.reserve(1000000);
for (int i = 0; i < n; ++i)
ans += a[i];
    puts(ans.c_str());
}
 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
   
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
 
    while (read()) {
        ld stime = gett();
        solve();
     //   cerr << "Time: " << gett() - stime << endl;
        //break;
    }
   
    return 0;
}