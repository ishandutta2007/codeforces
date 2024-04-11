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

using namespace std;

typedef long long ll;
const ll N = 1e6 + 7;

ll n, m, a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    b[m] = a[n - 1] + 34;
    int uk = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (b[uk] < a[i] - 1) uk++;
        if (b[uk] <= a[i] + 1) {
            ans++;
            uk++;
        }
    }
    cout << ans;
}