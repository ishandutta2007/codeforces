#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int mi = n - k + 1;
    ll a1 = (ll)n*(n + 1)/2 - (ll)mi*(mi - 1)/2;
    cout << a1 << ' ';
    ll wa = 1, cur = 0;
    bool fl = false;
    for(auto x : v) {
        if(x < mi) {
            cur++;
            continue;
        }
        if(!fl) {
            fl = true;
            cur = 0;
            continue;
        }
        wa = (wa * (cur + 1)) % MOD;
        cur = 0;
    }
    cout << wa << '\n';
}