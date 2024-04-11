#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << 2 << '\n';
        deque<int> d;
        for (int x = n; x >= 1; x--) d.pb(x);
        while (d.size() > 2) {
            int a = d[0], b = d[1], c = d[2];
            if (a % 2 != b % 2) {
                if (a % 2 == c % 2) {
                    swap(b, c);
                } else {
                    swap(a, c);
                }
            }
            d.pop_front();
            d.pop_front();
            d.pop_front();
            cout << a << ' ' << b << '\n';
            cout << (a + b + 1) / 2 << ' ' << c << '\n';
            d.push_front(((a + b + 1) / 2 + c) / 2);
        }
        if (d.size() == 2) {
            cout << d[0] << ' ' << d[1] << '\n';
        }
        cout << '\n';
    }
}