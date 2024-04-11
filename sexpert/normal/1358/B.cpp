#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    int ans = 1, cur = 1;
    v.push_back(-1);
    for(int i = 1; i <= n; i++) {
        if(v[i] == v[i - 1])
            cur++;
        else {
            if(cur + ans - 1 >= v[i - 1]) {
                ans += cur;
                cur = 1;
                continue;
            }
            cur++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();   
}