#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;
set<int> kekw;

void solve(int a, int b) {
    if (a > b) {
        cout << "NO\n";
    } else if (a == b) {
        cout << "YES\n";
    } else {
        vector<int> at, bt;
        for (int x = 0; x <= 30; x++) {
            if ((a >> x) & 1) {
                at.pb(x);
            }
            if ((b >> x) & 1) {
                bt.pb(x);
            }
        }
        if (bt.size() > at.size()) {
            cout << "NO\n";
        } else {
            sort(rall(at));
            sort(rall(bt));
            int j = 0;
            for (int i = 0; i < bt.size(); i++) {
                while (j < at.size() && bt[i] < at[j]) {
                    j++;
                }
                if (j == at.size()) {
                    cout << "NO\n";
                    return;
                }
                j++;
            }
            cout << "YES\n";
        }

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int b = 0; b <= 30; b++) {
        kekw.insert((1LL << b) - 1);
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }

}