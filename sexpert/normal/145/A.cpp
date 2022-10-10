#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ca = 0, cb = 0;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '4' && t[i] == '7')
            ca++;
        if(s[i] == '7' && t[i] == '4')
            cb++;
    }
    int ans = min(ca, cb);
    ca -= ans;
    cb -= ans;
    ans += ca + cb;
    cout << ans << '\n';
}