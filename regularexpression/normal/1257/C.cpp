#include<bits/stdc++.h>
using namespace std;
 
#define x first
#define y second
#define pb push_back
#define mp make_pair
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
 
#define ll long long
#define int long long
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> inds(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        inds[a[i]].push_back(i);
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(inds[i]) - 1; j++) {
            ans = min(ans, inds[i][j + 1] - inds[i][j] + 1);
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}