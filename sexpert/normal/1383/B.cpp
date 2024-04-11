#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(40, 0);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for(int d = 0; d < 30; d++) {
            if(a & (1 << d))
                cnt[d]++;
        }
    }
    for(int i = 29; i >= 0; i--) {
        if(cnt[i] % 2 == 0)
            continue;
        int f1 = ((cnt[i] + 1)/2), f2 = n - cnt[i];
        if(f1 % 2) {
            cout << "WIN\n";
            return;
        }
        if(f2 % 2)
            cout << "WIN\n";
        else
            cout << "LOSE\n";
        return;
    }
    cout << "DRAW\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}