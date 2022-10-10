#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    vector<array<int, 3>> ops;

    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum % n != 0) {
        cout << "-1\n";
        return;
    }

    for(int i = 2; i <= n; i++) {
        if(v[i] % i != 0) {
            int df = i - (v[i] % i);
            ops.push_back({1, i, df});
            v[1] -= df;
            v[i] += df;
        }
        ops.push_back({i, 1, v[i] / i});
        v[1] += v[i];
        v[i] = 0;
    }

    int tar = sum / n;
    for(int i = 2; i <= n; i++)
        ops.push_back({1, i, tar});

    cout << ops.size() << '\n';
    for(auto &[a, b, c] : ops)
        cout << a << " " << b << " " << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();    
}