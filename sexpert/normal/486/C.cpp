#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, p, ans = 0;
    string s;
    cin >> n >> p >> s;
    p--;
    for(int i = 0; i < n - 1 - i; i++) {
        int d1 = s[i] - 'a', d2 = s[n - 1 - i] - 'a';
        int dif = abs(d1 - d2);
        ans += min(dif, 26 - dif);
    }
    if(ans == 0) {
        cout << "0\n";
        return 0;
    }
    if(p > n - 1 - p)
        p = n - 1 - p;
    int l, r;
    for(l = 0;;l++)
        if(s[l] != s[n - 1 - l])
            break;
    for(r = (n - 1)/2;;r--)
        if(s[r] != s[n - 1 - r])
            break;
    if(p <= l)
        ans += r - p;
    if(p >= r)
        ans += p - l;
    if(l < p && p < r)
        ans += r - l + min(p - l, r - p);
    cout << ans << '\n';
}