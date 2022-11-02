#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

string get(string s, int k) {
    int n = s.size();
    string have = s.substr(k - 1, n - k + 1) + s.substr(0, k - 1);
    if ((n - k) % 2 == 0) reverse(have.end() - k + 1, have.end());
    return have;
}

string stupid_get(string s, int k) {
    cout << s << " ";
    for (int i = 0; i + k - 1 < s.size(); i++) {
        cout << i << " " << i + k - 1 << " ";
        reverse(s.begin() + i, s.begin() + i + k);
        cout << s << " ";
    }
    return s;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*string s = "abcd";
    for (int k = 1; k <= s.size(); k++) {
        cout << get(s, k) << endl;
    }
    cout << endl;*/

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = s;
        int fans = 1;
        for (int check = 2; check < n; check++) {
            string have = get(s, check);
            //cout << "check = " << check << " have = " << have << " " << stupid_get(s, check) << endl;
            if (have < ans) {
                ans = have;
                fans = check;
            }
        }
        reverse(all(s));
        if (s < ans) {
            ans = s;
            fans = n;
        }
        cout << ans << "\n";
        cout << fans << "\n";
    }
    return 0;
}