#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    string p = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && t[i] == '1') p.pb('0');
        if (s[i] == '1' && t[i] == '0') p.pb('1');
    }
    if (count(all(p), '0') != count(all(p), '1')) {
        cout << "-1\n";
        return 0;
    }
    int ans = 0, cur0 = 0, cur1 = 0;
    for (auto c : p) {
        if (c == '0') {
            if (cur1 == 0) {
                ans++;
                cur1++;
            }
            cur1--;
            cur0++;
        } else {
            if (cur0 == 0) {
                ans++;
                cur0++;
            }
            cur0--;
            cur1++;
        }
    }
    cout << ans;
    return 0;
}