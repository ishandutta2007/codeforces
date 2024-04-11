#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> lol;
    for(auto &x : v) {
        cin >> x;
        lol.insert(x);
    }
    if(!lol.count(1)) {
        cout << "YES\n";
        return;
    }
    for(auto &x : v) {
        if(lol.count(x + 1)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}