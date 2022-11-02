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
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;

string s[N], t[N];
int last_time[N];
pair<int, string> ans[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        static char buf[111];
        scanf("%s", buf);
        s[i] = string(buf);
        t[i] = s[i];
    }
    sort(t, t + n);
    int m = unique(t, t + n) - t;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(t, t + m, s[i]) - t;
        last_time[pos] = i;
    }
    for (int i = 0; i < m; ++i) {
        ans[i] = mp(last_time[i], t[i]);
    }
    sort(ans, ans + m);
    reverse(ans, ans + m);
    for (int i = 0; i < m; ++i) {
        printf("%s\n", ans[i].sc.data());
    }
    return 0;
}