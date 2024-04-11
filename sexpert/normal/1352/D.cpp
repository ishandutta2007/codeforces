#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, a = 0, b = 0, t = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int l = -1, r = n, prv = 0;
    while(l + 1 < r) {
        t++;
        if(t % 2) {
            int cur = 0;
            do {
                cur += v[++l];
            } while(cur <= prv && l + 1 < r);
            a += cur;
            prv = cur;
        }
        else {
            int cur = 0;
            do {
                cur += v[--r];
            } while(cur <= prv && l + 1 < r);
            b += cur;
            prv = cur;
        }
    }
    cout << t << " " << a << " " << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}