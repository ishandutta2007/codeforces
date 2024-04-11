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


void read() {
    int n = nxt();
    string s;
    cin >> s;

    vector <int> cnt(3);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            cnt[0]++;
        }
        if (s[i] == 'G') {
            cnt[1]++;
        }
        if (s[i] == 'R') {
            cnt[2]++;
        }
    }

    char used[n + 1][n + 1][n + 1];
    clr(used);

    used[cnt[0]][cnt[1]][cnt[2]] = 1;
    queue <vector <int> > q;
    q.push(cnt);

    int can[3];
    clr(can);

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (int i = 0; i < 3; ++i) {
            if (v[i] > 1) {
                auto to = v;
                to[i] -= 1;
                if (!used[to[0]][to[1]][to[2]]) {
                    used[to[0]][to[1]][to[2]] = 1;
                    q.push(to);
                }
            }
            if (v[i]) {
                for (int j = i + 1; j < 3; ++j) {
                    if (v[j]) {
                        auto to = v;
                        to[i] -= 1;
                        to[j] -= 1;
                        for (int k = 0; k < 3; ++k) {
                            if (k != i && k != j) {
                                to[k] += 1;
                            }
                        }
                        if (!used[to[0]][to[1]][to[2]]) {
                            used[to[0]][to[1]][to[2]] = 1;
                            q.push(to);
                        }
                    }
                }
            }
        }
        if (accumulate(all(v), 0) == 1) {
            int pos = find(all(v), 1) - v.begin();
            can[pos] = 1;
        }
    }
    string ans;
    if (can[0]) {
        ans += 'B';
    }

    if (can[1]) {
        ans += 'G';
    }

    if (can[2]) {
        ans += 'R';
    }
    cout << ans << endl;

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

//    test();
//    solve2();

//    gen();

    int c = 0;
    while (t--) {
        //gen();
        read();
//        gen();
//        gen2();

    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}