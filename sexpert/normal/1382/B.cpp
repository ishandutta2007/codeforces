#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int wi = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    v.push_back(2);
    for(int i = 0; i < n; i++) {
        if(v[i] > 1) {
            cout << (wi ? "Second" : "First") << '\n';
            return;
        }
        wi ^= 1;
    }
    cout << (wi ? "First" : "Second") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}