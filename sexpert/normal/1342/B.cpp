#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string t;
    cin >> t;
    int n = t.size();
    int cnt[2] = {0, 0};
    for(auto c : t)
        cnt[c - '0']++;
    if(!cnt[0] || !cnt[1]) {
        cout << t << '\n';
        return;
    }
    for(int i = 0; i < n; i++)
        cout << "01";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}