#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <sstream>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int N = int(1e6);
const int MOD = int(1e9) + 7;
const int K = 6;

int a[N], k[N], s[N], ss[N], f[N], g[N], cnt[N], pw2[N + 100];
int pw[K];
int sz[(1 << K)];
int lst[(1 << K)][K];
int digits[K];

inline int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}

inline int get_digit(int a, int b) {
    return (a / pw[b]) % 10;
}

inline int add(int a, int b) {
    if ((a += b) >= MOD) {
        a -= MOD;
    }
    return a;
}

inline int sub(int a, int b) {
    if ((a -= b) < 0) {
        a += MOD;
    }
    return a;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        ++cnt[cur];
    }
    pw2[0] = 1;
    for (int i = 1; i < N + 100; ++i) {
        pw2[i] = mult(pw2[i - 1], 2);
    }
    for (int i = 0; i < (1 << K); ++i) {
        sz[i] = 0;
        for (int j = 0; j < K; ++j) {
            if ((i & (1 << j)) != 0) {
                lst[i][sz[i]++] = j;
            }
        }
    }
    pw[0] = 1;
    for (int i = 1; i < K; ++i) {
        pw[i] = pw[i - 1] * 10;
    }
    for (int i = N - 1; i >= 0; --i) {
        k[i] = cnt[i];
        ss[i] = mult(cnt[i], i);
        s[i] = mult(cnt[i], mult(i, i));
        for (int j = 0; j < K; ++j) {
            digits[j] = get_digit(i, j);
        }
        for (int j = 1; j < (1 << K); ++j) {
            int ni = i;
            bool good = true;
            for (int zz = 0; zz < sz[j]; ++zz) {
                int z = lst[j][zz];
                if (digits[z] < 9) {
                    ni += pw[z];
                } else {
                    good = false;
                    break;
                }
            }
            if (good) {
                if (sz[j] % 2 != 0) {
                    k[i] = add(k[i], k[ni]);
                    s[i] = add(s[i], s[ni]);
                    ss[i] = add(ss[i], ss[ni]);
                } else {
                    k[i] = sub(k[i], k[ni]);
                    s[i] = sub(s[i], s[ni]);
                    ss[i] = sub(ss[i], ss[ni]);
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (k[i] == 0) {
            f[i] = 0;
        } else {
            f[i] = mult(s[i], pw2[k[i] - 1]);
            if (k[i] >= 2) {
                int addd = sub(mult(ss[i], ss[i]), s[i]);
                addd = mult(addd, pw2[k[i] - 2]);
                f[i] = add(f[i], addd);
            }
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < K; ++j) {
            digits[j] = get_digit(i, j);
        }
        for (int j = 0; j < (1 << K); ++j) {
            int ni = i;
            bool good = true;
            for (int zz = 0; zz < sz[j]; ++zz) {
                int z = lst[j][zz];
                if (digits[z] < 9) {
                    ni += pw[z];
                } else {
                    good = false;
                    break;
                }
            }
            if (good) {
                if (sz[j] % 2 == 0) {
                    g[i] = add(g[i], f[ni]);
                } else {
                    g[i] = sub(g[i], f[ni]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans ^= (1LL * i * g[i]);
    }
    cout << ans << endl;
    return 0;
}