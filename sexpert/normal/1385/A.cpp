#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    vector<int> v(3);
    for(auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    if(v[1] != v[2]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << v[0] << " " << v[0] << " " << v[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}