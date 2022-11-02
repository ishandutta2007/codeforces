#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

//#define next next12345
//#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const ld PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
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

template<typename T = int>
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

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

long long t = 1e7 + 19;
long long mod = 1e9 + 7;

int k;

struct data {
    int cost[1001];
    data() {
        clr(cost);
    }
    vector <int *> ptrs;
    vector <int> vals;

    void set(int *x, int y) {
        ptrs.push_back(x);
        vals.push_back(*x);
        *x = y;
    }


    void add(int v, int w) {
        for (int i = k; i >= w; --i) {
            if (cost[i] < cost[i - w] + v) {
                set(cost + i, cost[i - w] + v);
            }
        }

    }
    long long getHash() {
        long long h = 0;
        for (int i = k; i >= 1; --i) {
            h = h * t + cost[i];
            h %= mod;
        }
        return h;
    }

    inline int getVersion() {
        return vals.size();
    }
    void revert(int version) {
        while (ptrs.size() > version) {
            *ptrs.back() = vals.back();
            ptrs.pop_back();
            vals.pop_back();
        }
    }
} dsu;

enum Type {
    GET, UPDATE
};

struct Query {
    Type type;
    int l, r;
    int v, w;
};

void processQueries(vector <Query> & queries, int left, int right, vector <long long> & answer) {
    //cerr << left << " " << right << "\n";
    if (left == right) {
        int version = dsu.getVersion();
        for (const auto & query : queries) {
            if (query.type == UPDATE && query.l < left && query.r >= right) {
                dsu.add(query.v, query.w);
            }
        }
        for (const auto & query : queries) {
            if (query.type == GET && query.l == left) {
                answer[query.v] = dsu.getHash();
            }
        }
        dsu.revert(version);
        return;
    }

    int version = dsu.getVersion();

    vector <Query> queriesToSend;

    for (const auto & query : queries) {
        if (query.type == UPDATE && query.l < left && query.r >= right) {
            dsu.add(query.v, query.w);
        } else if ((query.type == GET && query.l >= left && query.r <= right) || (query.type == UPDATE && query.l < right && query.r >= left)) {
            queriesToSend.push_back(query);
        }
    }

    int mid = (left + right) / 2;

    processQueries(queriesToSend, left, mid, answer);
    processQueries(queriesToSend, mid + 1, right, answer);

    dsu.revert(version);
}

void solve(int test) {
    int n = nxt();
    k = nxt();


    int v[n + 20000];
    int w[n + 20000];
    int l[n + 20000];
    int r[n + 20000];

    for (int i = 0; i < n; ++i) {
        v[i] = nxt();
        w[i] = nxt();
        l[i] = 0;
    }

    int q = nxt();

    for (int i = 0; i < n; ++i) {
        r[i] = q + 1;
    }

    vector <Query> queries;

    int sz = n;

    for (int i = 1; i <= q; ++i) {
        //err << i << "\n";
        int type = nxt();
        //cerr << type << endl;
        if (type == 1) {
            v[sz] = nxt();
            w[sz] = nxt();
            l[sz] = i;
            r[sz] = q + 1;
            sz++;
            continue;
        }
        if (type == 2) {
            int id = nxt() - 1;
            r[id] = i;
            continue;
        }
        if (type == 3) {
            queries.push_back(Query{GET, i, i, i, i});
        }
    }

    for (int i = 0; i < sz; ++i) {
        queries.push_back(Query{UPDATE, l[i], r[i], v[i], w[i]});
    }

    vector <long long> ans(q + 1, -1);

    processQueries(queries, 0, q + 1, ans);

    for (long long x : ans) {
        if (x != -1) {
            cout << x << "\n";
        }
    }

}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sociology"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    //test();
#ifdef LOCAL
    int t = 1;
#else
    int t = 1;
#endif

    int c = 0;
    while (t--) {
        solve(++c);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}