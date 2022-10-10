#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> tot;
    string s;
    cin >> s;
    s += '$';
    int cnt = 1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != s[i - 1]) {
            if(s[i - 1] == 'v')
                tot.push_back(cnt - 1);
            cnt = 1;
        }
        else
            cnt++;
        if(s[i] == 'o')
            tot.push_back(-1);
    }
    ll ans = 0;
    ll prf = 0, sum = 0;
    for(auto x : tot) {
        if(x >= 0)
            sum += x;
    }
    for(auto x : tot) {
        if(x == -1)
            ans += prf * (sum - prf);
        else
            prf += x;
    }
    cout << ans << '\n';
}