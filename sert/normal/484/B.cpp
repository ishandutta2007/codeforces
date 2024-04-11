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

#define ff first
#define ss second

using namespace std;

typedef int ll;
const int N = 1e6 + 7;

int n, a[N];
int b[N];
int ans, ta, l, m, r;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = -1;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) continue;
        for (int j = a[i]; j <= 1000002; j += a[i])
            b[j] = a[i];
    }
    for (int i = 0; i <= 1000001; i++) {
        if (!b[i]) continue;
        l = 0;
        r = n;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (a[m] < i + b[i])
                l = m;
            else
                r = m;
        }
        if (a[l] >= i)
            ans = max(ans, a[l] - i);
    }
    cout << ans;
    return 0;
}