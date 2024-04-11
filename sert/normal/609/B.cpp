#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
ll n, m, a[N], ans, k;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> k;
        a[k - 1]++;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < i; j++)
            ans += a[i] * a[j];
    cout << ans;


    return 0;
}