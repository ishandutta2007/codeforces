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
#define all(s) (s).begin(), (s).end()
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
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
const double eps = 1e-4;
const double pi = 4 * atan(double(1));
const int N = 2020;

char buf[N];
int tmp[N], num[N];
bitset<N> val[N], used[N];
vi ans;

inline void build(int num) {
    int n = (int) strlen(buf);
    for (int i = 0; i < n; ++i) {
        tmp[i] = buf[i] - '0';
    }
    reverse(tmp, tmp + n);
    int ptr = 0;
    while (n > 0) {
        if (tmp[0] % 2 != 0) {
            val[num].set(ptr);
        }
        ++ptr;
        int ost = 0;
        for (int j = n - 1; j >= 0; --j) {
            tmp[j] += ost * 10;
            ost = tmp[j] % 2;
            tmp[j] /= 2;
        }
        while (n > 0 && tmp[n - 1] == 0) {
            --n;
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n;
    cin >> n;
    gets(buf);
    for (int i = 0; i < N; ++i) {
        num[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        gets(buf);
        build(i);
        bool good = true;
        for (int j = 0; j < N; ++j) {
            if (!val[i].test(j)) {
                continue;
            }
            if (num[j] == -1) {
                num[j] = i;
                good = false;
                break;
            }
            val[i] ^= val[num[j]];
            used[i] ^= used[num[j]];
        }
        if (good) {
            ans.clear();
            for (int j = 0; j < N; ++j) {
                if (used[i].test(j)) {
                    ans.pb(j);
                }
            }
            printf("%d", sz(ans));
            for (int j = 0; j < sz(ans); ++j) {
                printf(" %d", ans[j]);
            }
            puts("");
        } else {
            used[i].set(i);
            puts("0");
        }
    }
    return 0;
}