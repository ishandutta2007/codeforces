#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    ll ans = 0;
    ans += (2 * n - 1) / k + 1;
    ans += (5 * n - 1) / k + 1;
    ans += (8 * n - 1) / k + 1;
    cout << ans << endl;

    return 0;
}