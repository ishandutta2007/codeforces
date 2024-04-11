#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(auto &x : v)
            cin >> x;
        int s = accumulate(v.begin(), v.end(), 0);
        if(s % x != 0) {
            cout << n << '\n';
            continue;
        }
        int l = 0;
        while(l < n && v[l] % x == 0)
            l++;
        if(l == n) {
            cout << "-1\n";
            continue;
        }
        int r = n - 1;
        while(v[r] % x == 0)
            r--;
        cout << max(n - l - 1, r) << '\n';
    }
}