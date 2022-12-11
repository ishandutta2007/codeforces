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

int n, x, a[N], b[N];
ll ans;

bool is_prime(int x) {
    for (int i = 2; i * i <= n; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    init();
    cin >> n;
    bool prime = is_prime(n);

    if (prime) cout << 1;
    else if (n % 2 == 0 || is_prime(n - 2)) cout << 2;
    else cout << 3;

    return 0;
}