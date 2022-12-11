#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 34;
ll t;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ll n, k;
    cin >> n >> k;
    if (k >= n / 2) {
        cout << (n * (n - 1)) / 2;
        return 0;
    }

    t = n - k * 2;
    cout << (n * (n - 1)) / 2 - (t * (t - 1)) / 2;

    return 0;
}