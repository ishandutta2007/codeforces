#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

bool good(int l, int r) {
    if(r - l >= 8)
        return true;
    for(int i = l; i <= r - 2; i++) {
        for(int k = 1; i + 2*k <= r; k++) {
            if(s[i] == s[i + k] && s[i] == s[i + 2*k])
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    int n = s.length(), L = 0, R = 0;
    ll ans = 0;
    while(L < n) {
        if(R == n)
            break;
        if(!good(L, R))
            R++;
        else {
            ans += (ll)(n - R);
            L++;
        }
    }
    cout << ans << endl;
}