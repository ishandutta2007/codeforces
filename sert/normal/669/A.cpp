#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 34;
typedef double ld;
typedef long long ll;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ll n;
    cin >> n;
    cout << n / 3 * 2 + !!(n % 3);

    return 0;
}