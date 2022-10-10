#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main() {
    ll n;
    string s;
    cin >> n >> s;
    ll i = 0, pre = 0, suf = 0;
    while(i < n && s[i] == s[0]) {
        pre++;
        i++;
    }
    if(pre == n) {
        cout << n*(n + 1)/2ll << endl;
        return 0;
    }
    i = n - 1;
    while(i >= 0 && s[i] == s[n - 1]) {
        suf++;
        i--;
    }
    ll ans = (pre + suf + 1)%MOD;
    if(s[0] == s[n - 1])
        ans = (ans + pre*suf)%MOD;
    cout << ans << endl;
}