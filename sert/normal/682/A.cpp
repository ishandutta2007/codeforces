#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
typedef long double ld;
ll n, m, ans;
ll a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i % 5]++;
    for (int i = 1; i <= m; i++) b[i % 5]++;
    ans = a[0] * b[0] + a[1] * b[4] + a[2] * b[3] + a[3] * b[2] + a[4] * b[1];
    cout << ans;


    return 0;
}