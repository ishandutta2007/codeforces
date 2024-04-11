#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;
const int K = 30;

int a[N], l[N], r[N], q[N];
int add[K][N], sum[K][N];

inline int get_sum(int *sum, int l, int r) {
    return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &l[i], &r[i], &q[i]);
        --l[i];
        --r[i];
        for (int j = 0; j < K; ++j) {
            if ((q[i] & (1 << j)) != 0) {
                ++add[j][l[i]];
                --add[j][r[i] + 1];
            }
        }
    }
    for (int i = 0; i < K; ++i) {
        int bal = 0;
        for (int j = 0; j < n; ++j) {
            bal += add[i][j];
            if (j > 0) {
                sum[i][j] += sum[i][j - 1];
            }
            if (bal > 0) {
                a[j] |= (1 << i);
                ++sum[i][j];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int val = 0;
        for (int j = 0; j < K; ++j) {
            if (get_sum(sum[j], l[i], r[i]) == r[i] - l[i] + 1) {
                val |= (1 << j);
            }
        }
        if (val != q[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}