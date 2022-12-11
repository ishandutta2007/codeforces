#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int n, n1, n2;
int a[N];
ll sum1, sum2;

int main() {
    init();
    cin >> n >> n1 >> n2;
    if (n1 < n2) swap(n1, n2);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = n - 1; i >= n - n2; i--) sum2 += a[i];
    for (int i = n - n2 - 1; i >= n - n2 - n1; i--) sum1 += a[i];
    cout.precision(10);
    cout << fixed << (sum2 + 0.0) / (n2 + 0.0) + (sum1 + 0.0) / (n1 + 0.0);
    return 0;
}