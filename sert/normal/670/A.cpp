//made by Sert
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

ll a[N];
ll n, m, k, p, t;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    if (n % 7 == 0) {
        cout << n / 7 * 2 << " " << n / 7 * 2;
    }
    else if (n % 7 == 1)
        cout << n / 7 * 2 << " " << n / 7 * 2 + 1;
    else if (n % 7 == 6)
        cout << n / 7 * 2 + 1 << " " << n / 7 * 2 + 2;
    else
        cout << n / 7 * 2 << " " << n / 7 * 2 + 2;

    return 0;
}