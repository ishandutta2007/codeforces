#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    if(n == 1) {
        cout << "0\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k)
                cnt++;
        if(cnt == n) {
            cout << "1\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}