#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll total(ll k) {
    if(k == 0)
        return 0;
    ll p10 = 9, ans = 0, cur = 1;
    while(k >= p10) {
        ans += cur * p10;
        cur++;
        k -= p10;
        p10 = 10LL*p10;
    }
    ans += cur * k;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        ll k;
        cin >> k;
        ll bl = 0;
        while(total(bl + 1) < k) {
            k -= total(bl + 1);
            bl++;
        }
        //cout << bl << " " << k << endl;
        ll lo = 0, hi = 1e9;
        while(lo < hi) {
            ll mi = (lo + hi + 1)/2;
            if(total(mi) < k)
                lo = mi;
            else
                hi = mi - 1;
        }
        k -= total(lo);
        string s = to_string(lo + 1);
        //cout << k << " " << s << endl;
        cout << s[k - 1] << '\n';
    }
}