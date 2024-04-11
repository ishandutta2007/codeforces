#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
ll bef[MAXN], aft[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    if(x > y) {
        swap(x, y);
        for(auto &c : s) {
            if(c == '0')
                c = '1';
            else if(c == '1')
                c = '0';
        }
    }
    vector<int> bpos;
    ll c0 = 0, c1 = 0, cb = 0;
    ll cnt = 0, cur = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == '0')
            c0++;
        if(c == '1')
            c1++;
        if(c == '?') {
            cb++;
            bpos.push_back(i);
        }
        if(c == '0')
            cnt += cur;
        else
            cur++;
    }
    cur = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        bef[i] = cur;
        if(s[i] == '1')
            cur++;
    }
    cur = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        aft[i] = cur;
        if(s[i] == '0')
            cur++;
    }
    ll tot = (c1 + cb) * c0;
    ll ans = cnt * y + (tot - cnt) * x;
    //cout << cnt << '\n';
    for(int ch = 0; ch < cb; ch++) {
        int i = bpos[ch];
        //cout << i << " " << bef[i] << " " << aft[i] << '\n';
        cnt += bef[i];
        cnt -= aft[i];
        tot = (c1 + cb - ch - 1) * (c0 + ch + 1);
        ans = min(ans, cnt*y + (tot - cnt)*x);
    }
    cout << ans << '\n';
}