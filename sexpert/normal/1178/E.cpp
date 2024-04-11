#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, tmp;
    cin >> s;
    char final = '*';

    int n = s.size();
    int l = 0, r = n - 1;
    while(true) {
        if(l > r) break;
        if(l == r) {
            final = s[l];
            break;
        }
        if(s[l] == s[r]) {
            tmp += s[l];
            l++;
            r--;
            continue;
        }
        if(r == l + 1) {
            final = s[l];
            break;
        }
        if(s[l + 1] == s[r]) {
            tmp += s[l + 1];
            l += 2;
            r--;
            continue;
        }
        if(s[l] == s[r - 1]) {
            tmp += s[r - 1];
            l++;
            r -= 2;
            continue;
        }
        if(r == l + 2) {
            final = s[l];
            break;
        }
        tmp += s[l + 1];
        l += 2;
        r -= 2;
        continue;
    }
    string ans = tmp;
    if(final != '*')
        ans += final;
    reverse(tmp.begin(), tmp.end());
    ans += tmp;
    cout << ans << '\n';
}