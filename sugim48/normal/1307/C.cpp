#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

int main() {
    string s; cin >> s;
    int N = s.length();
    vector<int> a(26);
    for (char c: s) a[c - 'a']++;
    ll ans = 0;
    rep(k, 26) ans = max(ans, (ll)a[k]);
    for (char c1 = 'a'; c1 <= 'z'; c1++)
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            int cnt = 0;
            ll sum = 0;
            for (char c: s) {
                if (c == c2) sum += cnt;
                if (c == c1) cnt++;
            }
            ans = max(ans, sum);
        }
    cout << ans << endl;
}