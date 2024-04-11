#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), cnt(n + 1);
    int dif = 0, ma = 0;
    for(auto &x : v) {
        cin >> x;
        cnt[x]++;
        if(cnt[x] == 1)
            dif++;
        ma = max(ma, cnt[x]);
    }
    if(n == 1) {
        cout << "0\n";
        return;
    }
    cout << min(ma, dif) - (ma == dif) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}