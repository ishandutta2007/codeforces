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

const int N = 1000100;

struct Input {
    int n;
    int a[N];
    
    bool read () {
        if (scanf ("%d", &n) != 1)
            return 0;
        forn(i, n) {
            scanf ("%d", &a[i]);
        }
        return 1;
    }

    void init (const Input &input) {
        *this = input;
    }
};

struct Data: Input {
    int ans;    

    void write () {
        cout << ans << endl;
    }
    
    virtual void solve () {}
    
    virtual void clear () {
        *this = Data();
    }
};

struct Solution: Data {
    int p[N];
    int d[N];       

    void calc (vector<pair<int, int> >& q, int i, int cur, vector<int>& del) {
        if (i == (int)q.size()) {
            del.pb(cur);
            return;
        }
        for (int j = 0; j <= (int)q[i].sc; ++j) {
            calc(q, i + 1, cur, del);
            cur *= q[i].fs;     
        }
    }


    void solve () {
        memset(p, -1, sizeof(p));
        memset(d, 0, sizeof(d));
        p[0] = p[1] = 1;
        forn(i, 2, N) {
            if (p[i] >= 0) {
                continue;
            }
            p[i] = i;
            for (ll j = 1ll * i * i; j < N; j += i) {
                if (p[j] < 0)
                    p[j] = i;   
            }
        }
        forn(i, n) {
            int k = a[i];
            vector <int> q;
            while (k > 1) {
                q.pb(p[k]);
                k /= p[k];
            }
            sort(all(q));
            vector <pair<int, int> > st;
            for (int j = 0; j < int(q.size());) {
                int k = j;
                for (;k < (int)q.size() && q[j] == q[k]; ++k);
                st.pb(mp(q[j], k - j));
                j = k;
            }                      
            vector <int> del;
            calc(st, 0, 1, del);
            debug(a[i]);
            debug(all(del));
            if (a[i] == 1) {
                d[a[i]] = 1;
                continue;
            }
            forn(j, del.size()) {
                if (del[j] == a[i])
                    continue;
                umx(d[a[i]], d[del[j]] + 1);
            }
        }
        ans = 1;
        forn(i, N) {
            umx(ans, d[i]);
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