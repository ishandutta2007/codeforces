#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto &x : a)
        cin >> x;
    for(auto &x : b)
        cin >> x;
    ll g = 0;
    for(int i = 1; i < n; i++)
        g = __gcd(g, max(a[0], a[i]) - min(a[0], a[i]));
    for(int i = 0; i < m; i++)
        cout << __gcd(g, a[0] + b[i]) << " ";
    cout << '\n';
}