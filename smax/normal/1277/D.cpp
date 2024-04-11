#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int n00 = 0, n01 = 0, n10 = 0, n11 = 0;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;

            int type;
            if (s[0] == '0') {
                if (s.back() == '0') {
                    n00++;
                    type = 0;
                } else {
                    n01++;
                    type = 1;
                }
            } else {
                if (s.back() == '0') {
                    n10++;
                    type = 2;
                } else {
                    n11++;
                    type = 3;
                }
            }

            string r = s;
            reverse(r.begin(), r.end());
            if (mp[3-type].count(r))
                mp[3-type].erase(r);
            else
                mp[type].insert(make_pair(s, i + 1));
        }

        if (n01 == 0 && n10 == 0) {
            if (n00 > 0 && n11 > 0)
                cout << "-1\n";
            else
                cout << "0\n";
        } else if (n01 > n10 + 1) {
            int cnt = (n01 - n10) / 2;
            cout << cnt << "\n";
            for (auto p : mp[1]) {
                cout << p.second << " ";
                if (--cnt == 0)
                    break;
            }
            cout << "\n";
        } else if (n10 > n01 + 1) {
            int cnt = (n10 - n01) / 2;
            cout << cnt << "\n";
            for (auto p : mp[2]) {
                cout << p.second << " ";
                if (--cnt == 0)
                    break;
            }
            cout << "\n";
        } else
            cout << "0\n";

        for (int i=0; i<4; i++)
            mp[i].clear();
    }

    return 0;
}