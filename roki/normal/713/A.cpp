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
#define ft first
#define sc second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { out << "["; forn(i, sz(a)) { if (i) out << ','; out << ' ' << a[i]; } return out << " ]"; } 
template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int n;
const int N = 100 * 1000 + 5;
li x[N];   
char c[N];

inline bool read() {
	cin >> n;
    forn (i, n) {
        cin >> c[i];
        if (c[i] != '?')
            cin >> x[i];
        else {
            string s;
            cin >> s;
            int cur = 0;
            for (int j = 0; j < sz(s); ++j)
                cur = cur * 2 + s[j] - '0';
            x[i] = cur;
        }
    }
    return true;
}

int f(li x) {
    vector<int> v;
    while(x) {
        v.pb((x % 10) & 1);
        x /= 10;
    }
    reverse(all(v));
    int res = 0;
    forn (i, sz(v))
        res = res * 2 + v[i];
    return res;
}

inline void solve() {
    map<int, int> cnt;
    forn (i, n) {
        if (c[i] == '+')
            cnt[f(x[i])]++;
        if (c[i] == '-')
            cnt[f(x[i])]--;        
        if (c[i] == '?')
            cout << cnt[x[i]] << endl;
    }
}

int main() {
#ifdef _DEBUG
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    read();
    solve();

#ifdef _DEBUG
        cerr << "Time: " << clock() << endl;
#endif
	
    return 0;
}