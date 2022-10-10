#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    k = min(n, k);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int mx = 0, used = 0;
    while(true) {
        if(!cnt.count(mx)) {
            used++;
            if(used > k)
                break;
        }
        mx++;
    }
    mx = min(mx, n);
    vector<int> rem;
    for(auto [x, c] : cnt) {
        if(x >= mx)
            rem.push_back(c);
    }
    sort(rem.begin(), rem.end());
    int p = 0;
    while(p < rem.size() && k) {
        k--;
        rem[p]--;
        if(rem[p] == 0)
            p++;
    }
    int dif = mx;
    for(auto &x : rem)
        if(x > 0)
            dif++;
    cout << dif - mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}