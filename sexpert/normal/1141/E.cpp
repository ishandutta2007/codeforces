#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll H, n;
    cin >> H >> n;

    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;

    ll tmp = H, sum = 0, md = 0;
    for(int i = 0; i < n; i++) {
        tmp += v[i];
        sum += v[i];
        md = max(md, H - tmp);
        if(tmp <= 0) {
            cout << i + 1 << '\n';
            return 0;
        }
    }    
    if(sum >= 0) {
        cout << "-1\n";
        return 0;
    }
    ll dec = abs(sum);
    ll rd = max(((H - md)/dec) - 10, 0LL);
    ll tu = rd * n;
    H -= dec * rd;
    for(int i = 0;; i++) {
        if(H <= 0) {
            cout << tu + i << '\n';
            return 0;
        }
        H += v[i % n];
    }
}