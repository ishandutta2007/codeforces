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



long long bin[5][5];

void pre() {
    for (int i = 0; i < 5; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
        }
    }
}

void read() {

}




void test() {
//    auto l = get("99");
//    l.debug();
//    auto r = get("1");
//    r.debug();
//    auto d = merge(l, r);
//    d.debug();
//    exit(0);
}


long long mod = 1000000007;

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

void solve() {
    string a, b;
    cin >> b >> a;

    int mx[a.length()];
    int id[a.length()];
    int r[a.length()];
    for (int i = 0; i < a.length(); ++i) {
        string t = a.substr(i) + "#" + b;
        auto z = z_function(t);
        mx[i] = 0;
        for (int j = 0; j < b.length(); ++j) {
            if (z[z.size() - 1 - j] > mx[i]) {
                mx[i] = z[z.size() - 1 - j];
                id[i] = (int)b.length() - 1 - j;
                r[i] = 0;
            }
        }

        t = b;
        reverse(all(t));

        t = a.substr(i) + "#" + t;

        z = z_function(t);
        for (int j = 0; j < b.length(); ++j) {
            if (z[z.size() - 1 - j] > mx[i]) {
                mx[i] = z[z.size() - 1 - j];
                id[i] = (int)b.length() - 1 - j;
                r[i] = 1;
            }
        }
    }

    queue <int> q;
    int d[a.length() + 1];
    pair <int, int> pp[a.length() + 1];
    memset(d, 255, sizeof(d));
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == a.length()) {
            cout << d[v] << endl;
            vector <pair <int, int> > ans;
            while (v != 0) {
                ans.push_back(pp[v]);
                v -= abs(pp[v].x - pp[v].y) + 1;
            }
            reverse(all(ans));
            for (auto e : ans) {
                cout << e.x + 1 << " " << e.y + 1 << endl;
            }
            return;
        }

        for (int i = 1; i <= mx[v]; ++i) {
            if (d[v + i] == -1) {
                d[v + i] = d[v] + 1;
                if (r[v]) {
                    pp[v + i].x = b.length() - 1 - id[v];
                    pp[v + i].y = pp[v + i].x - i + 1;
                } else {
                    pp[v + i].x = id[v];
                    pp[v + i].y = id[v] + i - 1;
                }
                q.push(v + i);
            }
        }
    }
    puts("-1");
}

void solve2() {

}


int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "d"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
    pre();
#ifdef LOCAL
    test();
#endif
    while (t--) {
        read();
        solve();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}