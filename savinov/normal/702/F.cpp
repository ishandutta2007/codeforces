#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

typedef int itn;

#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

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

long long inv(long long a, long long p) {
    long long res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}

struct data {
    int pos;
    int cnt;
    int delta;
    int count;
};

struct client {
    int id;
    int money;
    int count;

    bool operator<(const client &r) const {
        return money < r.money;
    }
};

vector <client> clients;

const int MAGIC = 400;

void normalize(vector <data> &d) {
    for (auto x : d) {
        for (int i = x.pos; i < x.pos + x.cnt; ++i) {
            clients[i].money -= x.delta;
            clients[i].count += x.count;
        }
    }
    sort(all(clients));
    d.clear();
    d.push_back(data{0, (int)clients.size(), 0});
}

void buy(vector <data> &d, int cost) {
    if (d.size() > MAGIC) {
        normalize(d);
    }
    vector <data> nd;
    for (auto x : d) {
        if (clients[x.pos].money - x.delta >= cost) {
            x.delta += cost;
            x.count += 1;
            nd.push_back(x);
            continue;
        }
        if (clients[x.pos + x.cnt - 1].money - x.delta < cost) {
            nd.push_back(x);
            continue;
        }
        client temp{-1, cost + x.delta};

        int pos = lower_bound(clients.begin() + x.pos, clients.begin() + x.pos + x.cnt, temp) - clients.begin();

        data d1 = data{x.pos, pos - x.pos, x.delta, x.count};
        data d2 = data{pos, x.pos + x.cnt - pos, x.delta + cost, x.count + 1};

        nd.push_back(d1);
        nd.push_back(d2);
    }
    d.swap(nd);
}

void solve(int test) {
    int n = nxt();
    vector <pii> c(n);
    forn(i, n) {
        c[i].x = nxt();
        c[i].y = nxt();
    }

    sort(all(c), [&](const pii &l, const pii &r) {
        if (l.y != r.y) {
            return l.y > r.y;
        }
        return l.x < r.x;
    });

    int q = nxt();

    forn(i, q) {
        clients.push_back(client{i, nxt(), 0});
    }

    vector <data> d;

    normalize(d);

    for (auto p : c) {
        buy(d, p.x);
    }

    normalize(d);

    vi ans(q);

    for (auto c : clients) {
        ans[c.id] = c.count;
    }

    for (auto a : ans) {
        cout << a << "\n";
    }
}


int main(int argc, char **argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
#define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
//    pre();
//    test();
//    exit(0);
    int t = 1;

#ifdef LOCAL
#else
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