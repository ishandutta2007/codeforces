#pragma comment(linker, "/STACK:256000000")

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
const int N = int(1e6) + 100;
const int K = 100;
const int MAGIC = 100;

int n;
char buf[N];
int a[N];
vector<char> ops;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    gets(buf);
    int len = strlen(buf);
    char last = -1;
    ops.pb('+');
    for (int i = 0; i < len; ++i) {
        if (buf[i] == '+' || buf[i] == '-') {
            last = buf[i];
        } else if (buf[i] == '?') {
            if (last != -1) {
                ops.pb(last);
            }
        }
    }
    int i = 0;
    while (i < len && buf[i] != '=') {
        ++i;
    }
    assert(i < len);
    ++i;
    while (i < len && buf[i] == ' ') {
        ++i;
    }
    assert(i < len);
    n = 0;
    while (i < len && buf[i] >= '0' && buf[i] <= '9') {
        n = n * 10 + buf[i++] - '0';
    }
    int l = 0, r = 0;
    for (int i = 0; i < sz(ops); ++i) {
        if (ops[i] == '+') {
            l += 1;
            r += n;
        } else {
            l -= n;
            r -= 1;
        }
    }
    if (l <= n && n <= r) {
        int sum = 0;
        for (int i = 0; i < sz(ops); ++i) {
            a[i] = 1;
            if (ops[i] == '-') {
                sum -= a[i];
            } else {
                sum += a[i];
            }
        }
        while (sum != n) {
            bool changed = false;
            for (int i = 0; i < sz(ops); ++i) {
                if (a[i] < n) {
                    if (ops[i] == '+' && sum < n) {
                        changed = true;
                        ++a[i];
                        ++sum;
                    } else if (ops[i] == '-' && sum > n) {
                        changed = true;
                        ++a[i];
                        --sum;
                    }
                }
            }
            assert(changed);
        }
        puts("Possible");
        for (int i = 0; i < sz(ops); ++i) {
            if (i > 0) {
                printf(" %c ", ops[i]);
            }
            printf("%d", a[i]);
        }
        printf(" = %d\n", n);
    } else {
        puts("Impossible");
    }
    return 0;
}