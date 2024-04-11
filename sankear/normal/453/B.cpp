#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;

int n, ans;
vi cur, best;
bool used[200];
int bad[200], a[200], saved[200], d[200][200];

inline int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void doit(int cur, int add) {
    for (int i = 2; i * i <= cur; ++i) {
        if (cur % i == 0) {
            for (int j = i; j <= 60; j += i) {
                bad[j] += add;
            }
            while (cur % i == 0) {
                cur /= i;
            }
        }
    }
    if (cur > 1) {
        for (int j = cur; j <= 60; j += cur) {
            bad[j] += add;
        }
    }
}

void gen(int x, int y = 0) {
    if (x > 60) {
        if (d[y][n] < ans) {
            ans = d[y][n];
            best = cur;
        }
        return;
    }
    gen(x + 1, y);
    if (bad[x]) {
        return;
    }
    doit(x, 1);
    for (int i = 1; i <= n; ++i) {
        d[y + 1][i] = min(d[y][i], d[y + 1][i - 1] + (a[i - 1] - 1));
        d[y + 1][i] = min(d[y + 1][i], d[y][i - 1] + abs(a[i - 1] - x));
    }
    cur.pb(x);
    gen(x + 1, y + 1);
    cur.pop_back();
    doit(x, -1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        saved[i] = a[i];
        sum += a[i];
    }
    sort(a, a + n);
    for (int i = 1; i <= n; ++i) {
        d[0][i] = d[0][i - 1] + (a[i - 1] - 1);
    }
    ans = sum - n;
    gen(2);
    for (int i = 1; i <= sz(best); ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] = min(d[i - 1][j], d[i][j - 1] + (a[j - 1] - 1));
            d[i][j] = min(d[i][j], d[i - 1][j - 1] + abs(a[j - 1] - best[i - 1]));
        }
    }
    cerr << d[sz(best)][n] << endl;
    int i = sz(best), j = n;
    vector<pii> sol;
    while (i > 0 && j > 0) {
        if (d[i - 1][j - 1] + abs(a[j - 1] - best[i - 1]) == d[i][j]) {
            sol.pb(mp(a[j - 1], best[i - 1]));
            --i;
            --j;
            continue;
        }
        if (d[i - 1][j] == d[i][j]) {
            --i;
        } else {
            --j;
        }
    }
    for (int i = 0; i < n; ++i) {
        int res = 1;
        for (int j = 0; j < sz(sol); ++j) {
            if (!used[j] && sol[j].fs == saved[i]) {
                used[j] = true;
                res = sol[j].sc;
                break;
            }
        }
        cout << res << " ";
    }
    cout << endl;
    return 0;
}