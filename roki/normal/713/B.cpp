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

pair<pt, pt> p1;
pair<pt, pt> p2;


void gen() {
    n = (1 << 16);
    vector<int> x, y;
    forn (i, 4)
        x.pb(rand() + 1);
    forn (i, 4)
        y.pb(rand() + 1);
    sort(all(x));
    sort(all(y));        
    if (false) {
        p1 = {{x[0], x[1]}, {y[0], y[2]}};
        p2 = {{x[2], x[3]}, {y[1], y[3]}};        
    } else {
        p1 = {{x[0], x[2]}, {y[0], y[1]}};
        p2 = {{x[1], x[3]}, {y[2], y[3]}};        
    }   
}

bool check = false;

inline bool read() {
    if (check) {
        gen();
        return true;
    }	
    cin >> n;
    return true;
}

int cnt = 0;

int mq(int lx, int rx, int ly, int ry) {
    assert(lx >= 1 && rx <= n && ly >= 1 && ry <= n);
    assert(lx <= rx && ly <= ry);
    cnt++;
    if (check) {
        int res = 0;
        if (lx <= p1.x.x && p1.x.y <= rx && ly <= p1.y.x && p1.y.y <= ry)
            res++;
        if (lx <= p2.x.x && p2.x.y <= rx && ly <= p2.y.x && p2.y.y <= ry)
            res++;
        return res;
    }
    cout << "? " << lx << ' ' << ly << ' ' << rx << ' ' << ry << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

pair<pt, pt> findsq(int lx, int rx, int ly, int ry) {
    for (int i = 16; i >= 0; --i)
        if (lx + (1 << i) <= rx)
        if (mq(lx + (1 << i), rx, ly, ry) == 1)
            lx += 1 << i;
    for (int i = 16; i >= 0; --i)
        if (rx - (1 << i) >= lx)
        if (mq(lx, rx - (1 << i), ly, ry) == 1)
            rx -= 1 << i;
    for (int i = 16; i >= 0; --i)
        if (ly + (1 << i) <= ry)
        if (mq(lx, rx, ly + (1 << i), ry) == 1)
            ly += 1 << i;
    for (int i = 16; i >= 0; --i)
        if (ry - (1 << i) >= ly)
        if (mq(lx, rx, ly, ry - (1 << i)) == 1)
            ry -= 1 << i;
    return mp(mp(lx, rx), mp(ly, ry));
}

inline void solve() {
    int rx = 0;
    for (int i = 16; i >= 0; --i) 
        if (rx + (1 << i) <= n)
        if (mq(1, rx + (1 << i), 1, n) == 0)
            rx += 1 << i;

    if (mq(1, rx + 1, 1, n) == 1 && mq(rx + 2, n, 1, n) == 1) {
        pair<pt, pt> ans1 = findsq(1, rx + 1, 1, n);
        pair<pt, pt> ans2 = findsq(rx + 2, n, 1, n);
        if (mq(ans1.x.x, ans1.x.y, ans1.y.x, ans1.y.y) == 1) {
        if (mq(ans2.x.x, ans2.x.y, ans2.y.x, ans2.y.y) == 1) {
            cout << "! " << ans1.x.x << ' ' << ans1.y.x << ' ' << ans1.x.y << ' ' << ans1.y.y;
            cout << ' ' << ans2.x.x << ' ' << ans2.y.x << ' ' << ans2.x.y << ' ' << ans2.y.y << endl; 
            if (check) {
                assert((ans1 == p1 && ans2 == p2) || (ans1 == p2 && ans2 == p1));
            }
            cerr << cnt << endl;   
            return;
        }
        }
    }
    cerr << cnt << endl;
                                  

    int ry = 0;
    for (int i = 16; i >= 0; --i)
        if (ry + (1 << i) <= n)
        if (mq(1, n, 1, ry + (1 << i)) == 0)
            ry += 1 << i;

    pair<pt, pt> ans1 = findsq(1, n, 1, ry + 1);
    pair<pt, pt> ans2 = findsq(1, n, ry + 2, n);

    cout << "! " << ans1.x.x << ' ' << ans1.y.x << ' ' << ans1.x.y << ' ' << ans1.y.y;
    cout << ' ' << ans2.x.x << ' ' << ans2.y.x << ' ' << ans2.x.y << ' ' << ans2.y.y << endl; 
    if (check) {
        assert((ans1 == p1 && ans2 == p2) || (ans1 == p2 && ans2 == p1));
    }
    cerr << cnt << endl;
}

int main() {
#ifdef _DEBUG
   // assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif

    srand(time(NULL));

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    read();
    solve();

#ifdef _DEBUG
        cerr << "Time: " << clock() << endl;
#endif
	
    return 0;
}