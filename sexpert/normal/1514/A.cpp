#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<int> sq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1; i <= 100; i++)
        sq.insert(i * i);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &x : v)
            cin >> x;
        bool good = false;
        for(auto &x : v) {
            if(!sq.count(x)) {
                cout << "YES\n";
                good = true;
                break;
            }
        }
        if(!good)
            cout << "NO\n";
    }
}