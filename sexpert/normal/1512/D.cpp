#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n + 2);

    for(auto &x : b)
        cin >> x;

    sort(b.begin(), b.end());
    ll sum = accumulate(b.begin(), b.end(), 0LL);
    for(int i = 0; i <= n; i++) {
        if(sum - b[i] == 2 * b[n + 1]) {
            for(int j = 0; j < n + 1; j++) {
                if(j == i)
                    continue;
                cout << b[j] << " ";
            }
            cout << '\n';
            return;
        }
    }
    if(sum - b[n + 1] == 2 * b[n]) {
        for(int j = 0; j < n; j++)
            cout << b[j] << " ";
        cout << '\n';
        return;
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