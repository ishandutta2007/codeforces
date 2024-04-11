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
const int N = int(2e6) + 100;
const int MOD = int(1e9) + 7;
const int K = 30;

int cnt[K];
pii a[K];
char s[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    scanf("%s", s);
    int m = strlen(s);
    for (int i = 0; i < k; ++i) {
        a[i].fs = -1;
        a[i].sc = i;
    }
    for (int i = 0; i < m; ++i) {
        a[s[i] - 'a'].fs = i;
    }
    sort(a, a + k);
    for (int i = 0; i < n; ++i) {
        s[m++] = 'a' + a[i % k].sc;
    }
    for (int i = 0; i < m; ++i) {
        int new_sum = 1;
        for (int j = 0; j < k; ++j) {
            new_sum += cnt[j];
            if (new_sum >= MOD) {
                new_sum -= MOD;
            }
        }
        cnt[s[i] - 'a'] = new_sum;
    }
    int ans = 1;
    for (int i = 0; i < k; ++i) {
        ans += cnt[i];
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}