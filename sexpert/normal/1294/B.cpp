#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    vector<ii> v(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    int x = 0, y = 0;
    bool can = true;
    string ans;
    sort(v.begin(), v.end());
    for(auto p : v) {
        if(x > p.first || y > p.second)
            can = false;
        else {
            while(x < p.first) {
                x++;
                ans += 'R';
            }
            while(y < p.second) {
                y++;
                ans += 'U';
            }
        }
    }
    if(can)
        cout << "YES\n" << ans << '\n';
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}