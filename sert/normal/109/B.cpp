#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string pr, cur;
const int N = 1e6 + 34;
typedef long long ll;
const ll inf = 1e12;
string nxt(string s) {
    pr = s;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '4') {
            s[i] = '7';
            break;
        }
        s[i] = '4';
    }
    if (pr > s)
        s = "4" + s;
    return s;
}
ll val(string s) {
    ll ans = 0;
    for (int i = 0; i < s.length(); i++)
        ans = ans * 10ll + s[i] - '0';
    return ans;
}
ll per(ll l1, ll r1, ll l2, ll r2) {
    //cerr << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
    return max(0ll, min(r1, r2) - max(l1, l2) + 1ll);
}
ll lucky[N];
ll al, ar, bl, br, k, len = 1, kol, our, uk;
ll ad1, ad2;
int main() {
    //freopen("a.in", "r", stdin);
    cin >> al >> ar >> bl >> br >> k;
    lucky[len++] = 0;
    cur = "4";
    while (val(cur) < inf) {
        lucky[len++] = val(cur);
        cur = nxt(cur);
    }
    //cerr << cur << " " << len << "\n";
    for (int i = 1; lucky[i + k - 1] <= max(ar, br); i++) {
        //cerr << i << "\n";
        ad1 = per(lucky[i - 1] + 1, lucky[i], al, ar) * per(lucky[i + k - 1], lucky[i + k] - 1, bl, br);
        ad2 = per(lucky[i - 1] + 1, lucky[i], bl, br) * per(lucky[i + k - 1], lucky[i + k] - 1, al, ar);
        our += ad1 + ad2;
        if (ad1 >= 1 && ad2 >= 1 && k == 1)
            our--;
    }

    cout.precision(12);
    long double ans, ch, zn;
    ch = our;
    zn = (br - bl + 1) * (ar - al + 1);
    ans = ch / zn;
    cout << fixed << ans;
    return 0;
}