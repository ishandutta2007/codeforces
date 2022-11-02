#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <unistd.h>
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
#define len(s) sz(s)
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
const int N = int(1e5) + 100;

int sum[N];
char s[N];

inline int get_sum(int l, int r) {
    if (l > r) {
        return 0;
    }
    return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        sum[i] = (i > 0 ? sum[i - 1] : 0) + (s[i] == '0');
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            continue;
        }
        while (ans > 0) {
            int l = max(i - (ans - 1), 0), r = min(i + (ans - 1), n - 1);
            if (get_sum(l, r) >= k + 1) {
                --ans;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}