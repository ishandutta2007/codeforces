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

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

int U[1 << 20];
int divs[1 << 20];

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "onearmedbandit"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }


    int add[n + 1];
    clr(add);

    for (int i = 1; i < n; ++i) {
        int sz = 0;
        divs[sz++] = 0;
        int u = i - 1;
        for (int j = 1; j * j <= u; ++j) {
            divs[sz++] = j;
            divs[sz++] = u / j;
        }
        //sort(divs, divs + sz);
        //sz = unique(divs, divs + sz) - divs;

        for (int j = 0; j < sz; ++j) {

            int x = divs[j];
            if (U[x] == i) {
                continue;
            }
            U[x] = i;
            if (a[i] < a[x]) {

                int kmin = u / (x + 1);
                while (kmin * (x + 1) <= u) {
                    ++kmin;
                }
                while ((kmin - 1) * (x + 1) > u) {
                    --kmin;
                }
                int kmax;
                if (x == 0) {
                    kmax = n - 1;
                } else {
                    kmax = u / x;
                    while (kmax * x > u) {
                        --kmax;
                    }
                    while ((kmax + 1) * x <= u) {
                        ++kmax;
                    }
                }
                if (kmin <= kmax) {
                    add[kmin]++;
                    add[kmax + 1]--;
                }
            }

        }
    }
    int s = 0;
    for (int i = 0; i <= n; ++i) {
        s += add[i];
        add[i] = s;
    }

    for (int i = 1; i < n; ++i) {
        cout << add[i] << " ";
    }
    cout << "\n";


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}