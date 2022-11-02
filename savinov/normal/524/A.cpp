#include "bits/stdc++.h"

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
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
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int m = nxt(), k = nxt();

    map <int, set <int> > friends;

    set <int> p;

    map <int, set <int> > ans;


    for (int i = 0; i < m; ++i) {
        int a = nxt();
        int b = nxt();
        ans.insert({a, set<int>()});
        ans.insert({b, set<int>()});
        p.insert(a);
        p.insert(b);
        friends[a].insert(b);
        friends[b].insert(a);
    }


    for (int x : p) {
        for (int y : p) {
            if (x == y) continue;
            if (friends[x].count(y)) continue;
            int s = 0;
            for (int f : friends[y]) {
                if (friends[x].count(f)) {
                    ++s;
                }
            }
            if (s * 100 >= k * friends[x].size()) {
                ans[x].insert(y);
            }
        }
    }

    for (auto v : ans) {
        cout << v.x << ": ";
        cout << v.y.size();
        for (int d : v.y) {
            cout << " " << d;
        }
        cout << "\n";
    }



#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}