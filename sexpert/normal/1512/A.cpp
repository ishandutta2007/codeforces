#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    map<int, int> cnt, ps;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ps[x] = i;
        cnt[x]++;
    }
    for(auto &[x, c] : cnt) {
        if(c == 1)
            cout << ps[x] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}