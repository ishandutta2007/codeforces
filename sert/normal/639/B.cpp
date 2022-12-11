#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 34;
const ll INF = 3e18 + 20;

int n, d, h;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> d >> h;
    if (d < h || (d + 1) / 2 > h) {
        cout << "-1\n";
        return 0;
    }

    if (d == 1) {
        if (n == 2) {
            cout << "1 2\n";
        } else {
            cout << "-1\n";
        }
        return 0;
    }

    int k = min(h, d);
    for (int i = 0; i < k; i++)
        cout << i + 1 << " " << i + 2 << "\n";
    int cur = 1;
    for (int i = k; i < d; i++) {
        cout << cur << " " << i + 2 << "\n";
        cur = i + 2;
    }
    for (int i = d; i < n - 1; i++)
        cout << h << " " << i + 2 << "\n";


    return 0;
}