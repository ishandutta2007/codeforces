//
// Created by Evgeny Savinov on 09/01/2017.
//

#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
//typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
typedef unsigned int uint;

const ld PI = 3.1415926535897932384626433832795L;

template<class T>
bool uin(T &, const T &);

template<class T>
bool uax(T &, const T &);

template<class T>
T gcd(T, T);

template<class T>
T lcm(T, T);

template<class _T>
inline string tostr(const _T &);

template<typename T>
void input(T &);

template<typename T = long long>
T nxt();

bool checkp(long long);

template<typename T>
T pw(T a, T n, T p);

template<typename T>
T inv(T a, T p);

template<class _T>
_T sqr(const _T &x);

class range;

mt19937_64 gen;

int TTT;

const ll mod = 1000000007;


void pre() {
}



void solve(int test) {
    int n = nxt();
    int k = nxt();

    auto get = [&](int a, int c) {
        bitset <1500> res;
        for (int i = 0; i < n; ++i) {
            cout << "? " << a + 1 << " " << i + 1 << " " << c + 1 << endl;
            string x;
            cin >> x;
            if (x == "Yes") {
                res.set(i);
            }
        }
        return res;
//        a += 1;
//        c += 1;
//        int u = a;
//        while (true) {
//            int v = c;
//            while (v) {
//                if (v == u) {
//                    goto l1;
//                }
//                v >>= 1;
//            }
//            u >>= 1;
//            continue;
//            l1: break;
//        }
//
//        int lca = u;
//        bitset <1500> res;
//        while (a != lca) {
//            cerr << a << endl;
//            res[a - 1] = 1;
//            a >>= 1;
//        }
//        while (c != lca) {
//            cerr << c << endl;
//            res[c - 1] = 1;
//            c >>= 1;
//        }
//        res[lca - 1] = 1;
//        return res;

    };


    vector <int> cnt(n);
    vector <bitset <1500>> prev;
    forn(_, 60-3) {
        int a, b;
        do {
            a = rand() % n;
            b = rand() % n;
        } while (a == b);

        auto z = get(a, b);
//        for (auto p : prev) {
            auto q = z;
            for (int i = q._Find_first(); i < q.size(); i = q._Find_next(i)) {
                cnt[i] += 1;
            }
//        }
//        prev.pb(z);
    }
    vi o(n);
    iota(all(o), 0);
    sort(all(o), [&](int a, int b) {return cnt[a] > cnt[b];});

    if (k <= 3 && n >= 3) {
        forn(i, 3) forn(j, i) {
            auto p = get(o[i], o[j]);
            if (p.count() == 3) {
                p.reset(o[i]);
                p.reset(o[j]);
                cout << "! " << p._Find_first() + 1 << endl;
                return;
            }
        }
    }
    forn(i, n) cerr << cnt[i] << " ";
//    cout << "! " << max_element(cnt.begin(), cnt.end()) - cnt.begin() + 1 << endl;
    cout << "! " <<  o[0] + 1 << "\n";
}


int main(int argc, char **argv) {
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
#define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();

    ::TTT = 1;


#ifdef LOCAL
#else
#endif

    for (int test = 1; test <= ::TTT; ++test) {
        solve(test);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}


template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}


template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}


template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') {}
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = long long>
inline T nxt() {
    T res;
    input(res);
    return res;
}

void myassert(bool v) {
    assert(v);
//cout << "FAIL\n";
//exit(0);
}

mt19937 generator;

bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
T pw(T a, T n, T m) {
    T res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

template<typename T>
T inv(T a, T p) {
    T res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}


template<class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}