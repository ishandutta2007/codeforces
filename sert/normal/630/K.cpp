#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8001;
const ll md = 1e9 + 7;

ll p[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    p[0] = 0;
    int x;
    for (int i = 1; i <= 2520; i++) {
        x = 1;
        for (int j = 2; j <= 10; j++)
            if (i % j == 0)
                x = 0;
        p[i] = p[i - 1] + x;
    }

    ll n;
    cin >> n;
    cout << p[2520] * (n / 2520) + p[n % 2520];

    return 0;
}