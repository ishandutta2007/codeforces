#include<bits/stdc++.h>
using namespace std;
 
#define x first
#define y second
#define pb push_back
#define mp make_pair
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
 
#define ll long long
#define int long long
 
void solve() {
    int x, y;
    cin >> x >> y;
    while (x < y) {
        int z = x;
        if (x % 2 == 0) {
            x /= 2;
            x *= 3;
        } else {
            x--;
            x /= 2;
            x *= 3;
        }
        if (z >= x) {
            break;
        }
    }
    cout << (x >= y ? "YES\n" : "NO\n");
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}