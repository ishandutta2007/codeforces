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

int a[N], fen[N];

inline int get(int pos) {
    int res = 0;
    while (pos >= 0) {
        res += fen[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

inline void add(int pos) {
    while (pos < N) {
        ++fen[pos];
        pos = (pos | (pos + 1));
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    int l = 0, r = n - 1;
    while (l < r && k > 0) {
        swap(a[l++], a[r--]);
        --k;
    }
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += get(a[i] - 1);
        add(a[i]);
    }
    cout << ans << endl;
    return 0;
}