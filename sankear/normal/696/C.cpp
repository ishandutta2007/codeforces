#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int MOD = int(1e9) + 7;

int init[2][2], res[2][2], tmp[2][2];

inline void mult(int a[2][2], int b[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            tmp[i][j] = 0;
            for (int z = 0; z < 2; ++z) {
                tmp[i][j] = (tmp[i][j] + 1LL * a[i][z] * b[z][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = tmp[i][j];
        }
    }
}

void calc(ll n) {
    if (n == 1) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                res[i][j] = init[i][j];
            }
        }
        return;
    }
    if (n % 2 == 0) {
        calc(n / 2);
        mult(res, res);
    } else {
        calc(n - 1);
        mult(res, init);
    }
}

inline int calc(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 != 0) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    bool fl = true;
    init[0][0] = 1;
    init[0][1] = 2;
    init[1][0] = 1;
    init[1][1] = 0;
    int pw2 = 2;
    for (int i = 0; i < n; ++i) {
        ll cur;
        scanf("%lld", &cur);
        if (cur > 1) {
            fl = false;
        }
        calc(cur);
        for (int j = 0; j < 2; ++j) {
            for (int z = 0; z < 2; ++z) {
                init[j][z] = res[j][z];
            }
        }
        pw2 = calc(pw2, cur);
    }
    if (fl) {
        puts("0/1");
        return 0;
    }
    pw2 = (1LL * pw2 * calc(2, MOD - 2)) % MOD;
    int an1 = init[0][0], an = init[1][0];
    int a = an1 - an;
    if (a < 0) {
        a += MOD;
    }
    a = (1LL * a * calc(2, MOD - 2)) % MOD;
    cout << a << "/" << pw2 << endl;
    return 0;
}