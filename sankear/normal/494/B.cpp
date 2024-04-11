#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;
const int MOD = int(1e9) + 7;

int p[2 * N], sd[N], d[N];
char s[N], t[N], st[2 * N];
int sum[N];

inline int get_sum(int l, int r) {
    if (l > r) {
        return 0;
    }
    return sum[r] - sum[l - 1];
}

inline void norm(int &a) {
    while (a >= MOD) {
        a -= MOD;
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    gets(s);
    gets(t);
    int n = (int) strlen(s), m = (int) strlen(t);
    if (m > n) {
        puts("0");
        return 0;
    }
    int ptr = 0;
    for (int i = 0; i < m; ++i) {
        st[++ptr] = t[i];
    }
    st[++ptr] = '#';
    for (int i = 0; i < n; ++i) {
        st[++ptr] = s[i];
    }
    p[1] = 0;
    for (int i = 2; i <= ptr; ++i) {
        int j = p[i - 1];
        while (j > 0 && st[i] != st[j + 1]) {
            j = p[j];
        }
        if (st[j + 1] == st[i]) {
            p[i] = j + 1;
        } else {
            p[i] = 0;
        }
    }
    for (int i = m + 2; i <= ptr; ++i) {
        if (p[i] == m) {
            ++sum[i - (m + 1)];
        }
    }
    for (int i = 2; i <= n; ++i) {
        sum[i] += sum[i - 1];
    }
    d[0] = 1;
    sd[0] = 1;
    for (int i = 1; i <= n; ++i) {
        d[i] = d[i - 1];
        int pos = -1, l = 1, r = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (get_sum(mid + m - 1, i) > 0) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (pos != -1) {
            d[i] += sd[pos - 1];
            norm(d[i]);
        }
        sd[i] = sd[i - 1] + d[i];
        norm(sd[i]);
        cerr << d[i] << " ";
    }
    int ans = (d[n] - 1 + MOD);
    norm(ans);
    printf("%d\n", ans);
    return 0;
}