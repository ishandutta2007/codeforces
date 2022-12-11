#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>

#define ff first
#define ss second
#define y1 yy1
#define read(a, n) for (int i = 0; i < n; i++) cin >> a[i];

using namespace std;

typedef long long ll;
const ll N = 1e6 + 7;

ll n, m, a[N], b[N], ans, l;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> n >> l;
    read(a, n);
    sort(a, a + n);
    a[n++] = l * 2 - a[n - 1];
    a[n++] = -a[0];
    sort(a, a + n);
    for (int i = 1; i < n; i++)
        ans = max(ans, a[i] - a[i - 1]);
    cout << ans / 2 << "." << 5 * (ans % 2) << "\n";
}