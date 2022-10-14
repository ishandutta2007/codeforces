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
        int w, h, n;
        cin >> w >> h >> n;
        int a = 0, b = 0;
        while (w % 2 == 0) {
            a++;
            w /= 2;
        }
        while (h % 2 == 0) {
            b++;
            h /= 2;
        }
        if (pow(2, a + b) >= n) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }

}