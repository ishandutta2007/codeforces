#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    set<int> s;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < n; i++)
        s.insert(((i + v[i]) % n + n) % n);
    cout << (s.size() == n ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}