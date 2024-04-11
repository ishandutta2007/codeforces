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

int ans = 0;
bool used[7];

inline int calc(int x) {
    if (x == 0) {
        return 1;
    }
    int res = 0;
    while (x > 0) {
        ++res;
        x /= 7;
    }
    return res;
}

void gen(int x, int n, int m, int a, int b, ll va, ll vb) {
    if (x >= a + b) {
        ++ans;
        //cerr << va << " " << vb << endl;
        return;
    }
    for (int i = 0; i < 7; ++i) {
        if (!used[i]) {
            ll nva = va, nvb = vb;
            if (x < a) {
                nva = nva * 7 + i;
                if (nva >= n) {
                    continue;
                }
            } else {
                nvb = nvb * 7 + i;
                if (nvb >= m) {
                    continue;
                }
            }
            used[i] = true;
            gen(x + 1, n, m, a, b, nva, nvb);
            used[i] = false;
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int a = calc(n - 1), b = calc(m - 1);
    gen(0, n, m, a, b, 0, 0);
    cout << ans << endl;
    return 0;
}