#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 5050;
const int MOD = int(1e9) + 7;

int d[N], nd[N];

inline void norm(int &a) {
    while (a >= MOD) {
        a -= MOD;
    }
    while (a < 0) {
        a += MOD;
    }
}

inline void add(int l, int r, int val) {
    if (l > r) {
        return;
    }
    nd[l] += val;
    norm(nd[l]);
    nd[r + 1] -= val;
    norm(nd[r + 1]);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k, a, b;
    cin >> n >> a >> b >> k;
    --a;
    --b;
    for (int i = 0; i < n; ++i) {
        d[i] = 0;
    }
    d[a] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            nd[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (j == b) {
                continue;
            }
            if (j < b) {
                add(max(2 * j - b + 1, 0), j - 1, d[j]);
                add(j + 1, b - 1, d[j]);
            } else {
                add(b + 1, j - 1, d[j]);
                add(j + 1, min(2 * j - b - 1, n - 1), d[j]);
            }
        }
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += nd[j];
            norm(cur);
            d[j] = cur;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += d[i];
        norm(ans);
    }
    cout << ans << endl;
    return 0;
}