#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const long double EPS = 1e-12;

ll n, ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    while (n) {
        ans += n % 2;
        n /= 2;
    }
    cout << ans;

    return 0;
}