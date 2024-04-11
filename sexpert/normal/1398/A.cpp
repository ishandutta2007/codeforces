#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &x : v)
            cin >> x;
        if(v[0] + v[1] > v[n - 1]) {
            cout << "-1\n";
            continue;
        }
        cout << "1 2 " << n << '\n';
    }
}