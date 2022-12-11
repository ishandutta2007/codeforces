#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int n, a[N], ans, sum;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    ans = 1;
    sum = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] >= sum) {
            sum += a[i];
            ans++;
        }
    }

    cout << ans;

    return 0;
}