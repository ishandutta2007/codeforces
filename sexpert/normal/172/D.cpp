#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e7 + 10;
int res[MAX];

int main() {
    for(int d = 1; d <= 3500; d++)
        for(int k = d*d; k < MAX; k += d*d)
            res[k] = k / (d*d);
    int a, n;
    cin >> a >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += res[a + i];
    cout << ans << '\n';
}