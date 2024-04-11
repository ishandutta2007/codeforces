#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
typedef long double ld;
ll n, m, ans;
ll a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int cur = 1;
    for (int i = 0; i < n; i++)
        if (a[i] >= cur)
            cur++;
    cout << cur;

    return 0;
}