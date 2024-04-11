#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

ll n, m, c[N];
double ans = 0;
ll v1, v2, w;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d%I64d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%I64d", c + i);
    for (int i = 0; i < m; i++) {
        scanf("%I64d%I64d%I64d", &v1, &v2, &w);
        v1--;
        v2--;
        ans = max(ans, (c[v1] + c[v2] + 0.0) / (w + 0.0));
    }
    cout.precision(10);
    cout << fixed << ans;


    return 0;
}