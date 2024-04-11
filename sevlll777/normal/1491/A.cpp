#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        s += A[i];
    }
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            if (A[x - 1] == 1) {
                s--;
                A[x - 1] = 0;
            } else {
                s++;
                A[x - 1] = 1;
            }
        } else {
            if (s >= x) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }

}