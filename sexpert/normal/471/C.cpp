#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

// a1 > a2 > ... > ak
// 3a1 - 1 + 3a2 - 1 + ... + 3ak - 1 = 3(a1 + a2 + ... + ak) - k cards

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, ans = 0;
    cin >> n;

    for(ll k = 1;;k++) {
        if((n + k) % 3)
            continue;
        ll res = (n + k)/3;
        if( k*(k + 1)/2 > res)
            break;
        else
            ans++;
    }
    cout << ans << endl;
}