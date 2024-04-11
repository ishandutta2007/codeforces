#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <complex>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define prev _prev
#define link _link
#define hash _hash

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

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;
const int MOD = int(1e9) + 7;

int cnt[4];
char s[N];

inline int get_c(char ch) {
    if (ch == 'A') {
        return 0;
    }
    if (ch == 'C') {
        return 1;
    }
    if (ch == 'G') {
        return 2;
    }
    if (ch == 'T') {
        return 3;
    }
    assert(false);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; ++i) {
        ++cnt[get_c(s[i])];
    }
    int max_val = 0, k = 0;
    for (int i = 0; i < 4; ++i) {
        if (cnt[i] > max_val) {
            max_val = cnt[i];
            k = 0;
        }
        if (cnt[i] == max_val) {
            ++k;
        }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = (1LL * ans * k) % MOD;
    }
    cout << ans << endl;
    return 0;
}