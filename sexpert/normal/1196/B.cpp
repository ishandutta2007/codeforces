#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k, segs = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int res = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        res = (res + v[i])%2;
        if(res % 2 && (segs < k - 1 || i == n - 1)) {
            segs++;
            ans.push_back(i + 1);
            res = 0;
        }
    }
    if(segs == k) {
        cout << "YES\n";
        for(auto x : ans)
            cout << x << " ";
        cout << '\n';
    }
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
}