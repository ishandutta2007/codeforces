#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;

vector<pii> values, nvalues;
map<int, ll> ans;

inline int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        for (int j = 0; j < sz(values); ++j) {
            values[j].fs = gcd(values[j].fs, cur);
        }
        values.pb(mp(cur, 1));
        sort(values.begin(), values.end());
        int j = 0;
        nvalues.clear();
        while (j < sz(values)) {
            int z = j;
            while (z + 1 < sz(values) && values[j].fs == values[z + 1].fs) {
                ++z;
            }
            int sum = 0;
            for (int h = j; h <= z; ++h) {
                sum += values[h].sc;
            }
            nvalues.pb(mp(values[j].fs, sum));
            j = z + 1;
        }
        values.swap(nvalues);
        for (int j = 0; j < sz(values); ++j) {
            ans[values[j].fs] += values[j].sc;
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        ll res;
        if (ans.find(x) != ans.end()) {
            res = ans[x];
        } else {
            res = 0;
        }
        printf(LLD"\n", res);
    }
    return 0;
}