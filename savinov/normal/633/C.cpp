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

const int K = 26;

struct vertex {
    int next[K];
    int leaf;
};

vertex t[1 << 21];
int sz;

void init() {
    memset (t[0].next, 255, sizeof t[0].next);
    t[0].leaf = -1;
    sz = 1;
}

void add_string (const string & s, int id) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        char c = tolower(s[i])-'a'; //    
        if (t[v].next[c] == -1) {
            memset (t[sz].next, 255, sizeof t[sz].next);
            t[sz].leaf = -1;
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    t[v].leaf = id;
}

void solve(int test) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dp[n + 1];
    clr(dp);
    int p[n + 1];
    int m;
    cin >> m;
    string x[m];
    init();
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
        add_string(x[i], i);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int v = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (t[v].next[s[j] - 'a'] == -1) {
                break;
            }
            v = t[v].next[s[j] - 'a'];
            if (t[v].leaf != -1 && dp[j]) {
                dp[i] = 1;
                p[i] = t[v].leaf;
                break;
            }
        }
    }
    assert(dp[n]);

    int pos = n;
    vector <string> ans;
    while (pos) {
        ans.push_back(x[p[pos]]);
        pos -= x[p[pos]].length();
    }
    reverse(all(ans));
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
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
    int t = 1;
//    pre();
#ifdef LOCAL
#endif
    ios_base::sync_with_stdio(false);

    int c = 0;
    while (t--) {
        solve(++c);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}