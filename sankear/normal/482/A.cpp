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

int a[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    a[0] = 1;
    --k;
    int pos = 1, l = 2, r = n;
    for (int i = 0; i < k; ++i) {
        if (pos % 2 != 0) {
            a[pos++] = r--;
        } else {
            a[pos++] = l++;
        }
    }
    int ptr = pos;
    for (int i = l; i <= r; ++i) {
        a[pos++] = i;
    }
    if (abs(a[ptr] - a[ptr - 1]) != 1) {
        reverse(a + ptr, a + n);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}