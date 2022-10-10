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
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum % n) {
            cout << "-1\n";
            continue;
        }
        int av = sum / n, ans = 0;
        for(auto &x : v)
            if(x > av) ans++;
        cout << ans << '\n';
    }
}