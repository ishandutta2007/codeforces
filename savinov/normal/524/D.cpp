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

    int n = nxt(), M = nxt(), t = nxt();

    vector <int> add[100000];
    vector <int> era[100000];

    int r[n];

    for (int i = 0; i < n; ++i) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int v = h * 3600 + m * 60 + s;
        add[v].push_back(i);
        era[v + t - 1].push_back(i);
        r[i] = v;
    }

    char ok = false;

    int ans = 0;

    auto cmp = [&](int x, int y) {
        return r[x] > r[y] || (r[x] == r[y] && x < y);
    };

    set <int, decltype(cmp)> q(cmp);

    int color[n];

    int cnt[100000];
    clr(cnt);

    int colors = 0;

    for (int i = 0; i < 100000; ++i) {
        for (int a : add[i]) {
            if (colors == M) {
                int v = *q.begin();
                color[a] = color[v];
                cnt[color[a]]++;
                q.insert(a);
            } else {
                color[a] = ans;
                cnt[ans++]++;
                colors++;
                q.insert(a);
            }
        }
        if (colors == M) {
            ok = true;
        }

        for (int e : era[i]) {
            cnt[color[e]]--;
            if (cnt[color[e]] == 0) {
                --colors;
            }
            q.erase(e);
        }
    }

    if (!ok) {
        puts("No solution");
    } else {
        cout << ans << "\n";
        for (int i = 0; i < n; ++i) {
            cout << color[i] + 1 << "\n";
        }
    }

#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}