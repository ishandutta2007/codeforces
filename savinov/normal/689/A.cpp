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

void solve(int test) {
    map <int, PII> m;
    m[1] = {0, 0};
    m[2] = {0, 1};
    m[3] = {0, 2};

    m[4] = {1, 0};
    m[5] = {1, 1};
    m[6] = {1, 2};

    m[7] = {2, 0};
    m[8] = {2, 1};
    m[9] = {2, 2};
    
    m[0] = {3, 1};

    map <PII, int> t;

    for (auto x : m) {
        t[x.y] = x.x;
    }


    

    int n = nxt();
    string ss;
    cin >> ss;

    vector <pair <int, int> > dx;

    for (int i = 1; i < n; ++i) {
        PII S = m[ss[i - 1] - '0'];
        PII T = m[ss[i] - '0'];

        PII delta = make_pair(T.x - S.x, T.y - S.y);
        dx.pb(delta);
    }
    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
        PII v = m[i];
        for (auto q : dx) {
            v.x += q.x;
            v.y += q.y;
            if (!t.count(v)) {
                goto l1;
            }
        }
        ++cnt;
        l1:;
    }

    cerr << cnt << endl;

    puts(cnt > 1 ? "NO" : "YES");

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