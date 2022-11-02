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

pii a[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].fs, &a[i].sc);
    }
    sort(a, a + n);
    int ans = 0, i = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && a[j + 1].fs == a[i].fs) {
            ++j;
        }
        for (int z = i; z <= j; ++z) {
            if (a[z].sc >= ans) {
                ans = a[z].sc;
            } else {
                ans = a[z].fs;
            }
        }
        i = j + 1;
    }
    cout << ans << endl;
    return 0;
}