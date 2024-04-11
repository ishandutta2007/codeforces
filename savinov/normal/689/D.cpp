#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
typedef int itn;
using namespace std;
using vi = vector<int>;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;

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

struct data {
    set <int> f;
    data(int n) {
        f.insert(-1);
        f.insert(n);
    }

    void add(int x) {
        f.insert(x);
    }

    void remove(int x) {
        f.erase(x);
    }

    PII s(int x) {
        if (f.count(x)) {
            return {-1, -1};
        }
        auto p = f.lower_bound(x);
        auto q = p;
        --q;
        return {*q + 1, *p};
    }
};

void solve(int test) {
    int n = nxt();

    PII b[n];
    forn(i, n) {
        b[i] = {nxt(), i};
    }

    PII a[n];
    forn(i, n) {
        a[i] = {nxt(), i};
    }

    sort(a, a + n);
    sort(b, b + n);

    data MIN(n), MAX(n);
    forn(i, n) MAX.add(i);

    map <int, vector <int> > ids;

    set <int> tt;

    forn(i, n) {
        tt.insert(b[i].x);
        tt.insert(a[i].x);
    }

    for(auto x : tt) {
        ids[x].push_back(-1);
    }

    forn(i, n) {
        ids[b[i].x].push_back(b[i].y);
    }

    for (auto x : tt) {
        sort(all(ids[x]));
        ids[x].push_back(n);
    }

    int j = 0;

    long long ans = 0;
    forn(i, n) {
        while (j < n && b[j].x <= a[i].x) {
            MAX.remove(b[j].y);
            ++j;
        }
        auto s = MIN.s(a[i].y);

        auto t = MAX.s(a[i].y);

        if (t.x == -1) {
            MIN.add(a[i].y);
            continue;
        }

        s.x = max(s.x, t.x);
        s.y = min(s.y, t.y);

        ans += (a[i].y - s.x + 1) * (s.y - a[i].y);

//        cerr << a[i].y << endl;
//        cerr << ans << endl;
//        cerr << s.x << " " << s.y << endl;

        const auto &r = ids[a[i].x];

        auto it = lower_bound(all(r), a[i].y);
        auto it2 = upper_bound(all(r), a[i].y);

        if (*it != a[i].y) {
            --it2;

            s.x = max(s.x, *it2 + 1);
            s.y = min(s.y, *it);

            ans -= (a[i].y - s.x + 1) * (s.y - a[i].y);

//            cerr << s.x << " " << s.y << endl;
        }
        MIN.add(a[i].y);
    }

    cout << ans  << "\n";
}

int main(int argc, char **argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
#endif
#ifdef LOCAL
#else
#endif
//    init();
    int c = 0;
    int t = 1;
    while (t--) {
        solve(c++);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}