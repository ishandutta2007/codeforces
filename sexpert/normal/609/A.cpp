#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; i++) {
        m -= v[i];
        if(m <= 0) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}