#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> t;
    if (n == 1 && t == 10) {
        cout << -1;
        return 0;
    }
    if (n == 1) {
        cout << t;
        return 0;
    }
    k = 0;
    for (int i = 0; i < n - 1; i++) {
        cout << 1;
        k = (k * 10 + 1) % t;
    }
    cout << (t * 10 - k * 10) % t;
    //while (true);
    return 0;
}