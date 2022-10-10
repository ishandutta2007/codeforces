#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int M = *(max_element(v.begin(), v.end())), m = *(min_element(v.begin(), v.end()));
    if(M > m + 2*k) {
        cout << "-1\n";
        return;
    }
    cout << m + k << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
}