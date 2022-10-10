#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[3];

void solve() {
    memset(cnt, 0, sizeof cnt);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &x : a)
        cin >> x;
    for(auto &x : b)
        cin >> x;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i] && !cnt[0]) {
            cout << "NO\n";
            return;
        }
        if(a[i] < b[i] && !cnt[2]) {
            cout << "NO\n";
            return;
        }
        cnt[a[i] + 1]++;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}