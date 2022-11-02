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
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define LLD "%lld"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define LLD "%I64d"
#define eprintf(...)
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int n, m;
bool used[111];
vi cur;
int best = -inf;
vector<vi> ans;

void gen(int x) {
    if (x >= n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int val = inf;
            for (int j = i; j < n; ++j) {
                val = min(val, cur[j]);
                res += val;
            }
        }
        if (res > best) {
            best = res;
            ans.clear();
        }
        if (res == best) {
            ans.pb(cur);
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cur.pb(i);
            used[i] = true;
            gen(x + 1);
            used[i] = false;
            cur.pbk();
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    gen(0);
    for (int i = 0; i < n; ++i) {
        cout << ans[m - 1][i] + 1 << " ";
    }
    cout << endl;
    return 0;
}