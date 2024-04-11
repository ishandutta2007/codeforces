#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    
    if(n % 2) {
        cout << "NO\n";
        return;
    }

    sort(v.begin(), v.end());
    vector<int> ans;
    for(int i = n/2 - 1; i >= 0; i--) {
        ans.push_back(v[i + n/2]);
        ans.push_back(v[i]);
    }
    ans.push_back(v[n - 1]);
    ans.push_back(v[n/2 - 1]);

    for(int i = 1; i + 1 < v.size(); i += 2) {
        if(ans[i] >= ans[i - 1] || ans[i] >= ans[i + 1]) {
            cout << "NO\n";
            return;
        }
    }

    for(int i = 2; i + 1 < v.size(); i += 2) {
        if(ans[i] <= ans[i - 1] || ans[i] <= ans[i + 1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
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