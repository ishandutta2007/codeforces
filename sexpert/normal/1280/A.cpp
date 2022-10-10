#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
    int x, l = 0;
    cin >> x;
    string s;
    cin >> s;
    ll culen = s.size();
    while(s.size() < x) {
        string t = s.substr(l + 1);
        if(s[l] >= '2')
            s += t;
        if(s[l] >= '3')
            s += t;
        l++;
    }
    //cout << s << endl;
    for(int i = 0; i < x; i++)
        culen = (culen + (culen - i - 1)*(s[i] - '1')) % MOD;
    cout << (culen + MOD) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}