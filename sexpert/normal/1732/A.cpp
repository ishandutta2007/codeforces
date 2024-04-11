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
        if(n == 1) {
            cout << (v[0] > 1) << '\n';
            continue;
        }
        int g = 0;
        for(int i = 0; i < n - 2; i++)
            g = __gcd(g, v[i]);
        if(__gcd(__gcd(g, v[n - 2]), v[n - 1]) == 1) {
            cout << "0\n";
            continue;
        }
        if(__gcd(g, __gcd(v[n - 2], __gcd(v[n - 1], n))) == 1) {
            cout << "1\n";
            continue;
        }
        if(__gcd(g, __gcd(v[n - 1], __gcd(v[n - 2], n - 1))) == 1) {
            cout << "2\n";
            continue;
        }
        cout << "3\n";
    }
}