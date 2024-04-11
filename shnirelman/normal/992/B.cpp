#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

//istream& operator >>(istream& cin, vector<int>& a) {
//    for(int i = 0; i < a.size(); i++)
//        cin >> a;
//    return cin;
//}

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, r, x, y;
    cin >> l >> r >> x >> y;

    if(y % x) {
        cout << 0;
        return 0;
    }

    if(x == y) {
        if(l <= x && y <= r) {
            cout << 1;
        } else {
            cout << 0;
        }

        return 0;
    }

    int ans = 0;
    y /= x;
    for(int i = 1; i * 1ll * i <= y; i++) {
        if(y % i == 0) {
            int j = y / i;
//            cout << i << ' ' << j << endl;
            if(__gcd(i, j) == 1 && i * 1ll * x >= l && i * 1ll * x <= r && l <= j * 1ll * x && j * 1ll * x <= r) {
                ans += 2;//(i == j ? 1 : 2);
            }
        }
    }

    cout << ans;
//    vector<vector<int>> a(n, vector<>)
}