#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(auto &x : a)
        cin >> x;
    for(auto &x : b)
        cin >> x;
    for(auto &x : c)
        cin >> x;
    vector<int> v(n);
    v[0] = a[0];
    for(int i = 1; i + 1 < n; i++) {
        if(a[i] == v[i - 1])
            v[i] = b[i];
        else
            v[i] = a[i];
    }
    set<int> lol = {v[0], v[n - 2]};
    if(!lol.count(a[n - 1]))
        v[n - 1] = a[n - 1];
    if(!lol.count(b[n - 1]))
        v[n - 1] = b[n - 1];
    if(!lol.count(c[n - 1]))
        v[n - 1] = c[n - 1];

    for(auto &x : v)
        cout << x << " ";
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