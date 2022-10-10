#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, pref = 1, ans = 0;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i++) {
        pref *= 2;
        if(s[i] == 'b')
            pref--;
        if(t[i] == 'a')
            pref--;
        if(pref > 1e14)
            pref = 1e14;
        ans += min(k, pref);
    }
    cout << ans << endl;
}