#include <bits/stdc++.h>
using namespace std;

#ifdef SG
    #include <debug.h>
#else
    #define show(...)
    #define debug(...)
    #define deepen(...)
    #define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200100;
const int Q = 500100;

struct Input {
    int n, q;
    int x[Q], y[Q], tp[Q];
        
    bool read () {
        if (scanf ("%d %d", &n, &q) != 2)
            return 0;
        forn(i, q) {
            scanf ("%d %d %d", &tp[i], &x[i], &y[i]);
            x[i]--, y[i]--;
//          debug(mt(x[i], y[i], tp[i]));
        }   
        return 1;
    }

    void init (const Input &input) {
        *this = input;
    }
};

struct Data: Input {
    vector <bool> ans;

    void write () {
        forn(i, ans.size()) {
            if (ans[i]) {
                puts("YES");
            } else {
                puts("NO");
            }
        }   
    }
    
    virtual void solve () {}
    
    virtual void clear () {
        *this = Data();
    }
};

const int inf = 1000000000;

struct Solution: Data {
    int p[N];
    set <pair<pair<int, int>, int> > s;

    int get (int a) {
        if (a == p[a])
            return a;
        return p[a] = get(p[a]);
    }

    int rnd;

    bool uni (int l, int r) {
        l = get(l), r = get(r);
        if (l == r)
            return 0;
        if (rnd ^= 1)
            swap(l, r);
        p[l] = r;
        return 1;
    }

    int get_comp (int k) {
        auto x = s.upper_bound(mp(mp(k, inf), inf));    
        if (x != s.begin()) {
            --x;
        }
        return get(x->sc);
    }

    void solve () {
        rnd = 1;
        forn(i, n)
            p[i] = i;
        forn(i, n) {
            s.insert(mp(mp(i, i), i));  
        }
        forn(i, q) {
            if (tp[i] == 1) {
                int l = get_comp(x[i]), r = get_comp(y[i]);
                uni(l, r);      
            } else if (tp[i] == 2) {
                if (x[i] > y[i])
                    swap(x[i], y[i]);
                auto it = s.upper_bound(mp(mp(x[i], inf), inf));
                vector <pair<pair<int, int>, int> > q;
                if (it != s.begin()) {
                    it--;       
                }
                for (; it != s.end(); ++it) {
                    pair<pair<int, int>, int> k = *it;
                    if (k.fs.fs > y[i]) {
                        break;
                    }
                    q.pb(k);
                }
                forn(j, q.size() - 1) {
                    uni(q[j].sc, q[j + 1].sc);
                }
                int k1 = get(q[0].sc);
                forn(i, q.size()) {
                    s.erase(q[i]);
                }
                s.insert(mp(mp(q[0].fs.fs, q.back().fs.sc), k1));
            } else {
                int l = get_comp(x[i]), r = get_comp(y[i]);
                ans.pb((l == r));   
            }   
        }   
    }
    
    void clear () {
        *this = Solution();
    }
};

Solution sol;

int main () {
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
#ifdef SG
    freopen((problemname + ".in").c_str(), "r", stdin);
//  freopen((problemname + ".out").c_str(), "w", stdout);
#endif
    while (sol.read()) {
        sol.solve();
        sol.write();
        sol.clear();
    }
    return 0;
}