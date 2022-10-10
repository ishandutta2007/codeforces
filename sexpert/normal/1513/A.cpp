#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if(2 * k + 1 > n) {
        cout << "-1\n";
        return;
    }
    vector<int> v(n);
    int p = n;
    for(int i = 1; i < 1 + 2 * k; i += 2)
        v[i] = p--;
    p = 1;
    for(int i = 0; i < n; i++) {
        if(v[i])
            continue;
        v[i] = p++;
    }
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