#include <bits/stdc++.h>
using namespace std;

bool can[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        memset(can, false, sizeof(can));
        char c = '?';
        int cnt = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] != c) {
                if (c != '?' && cnt % 2)
                    can[c-'a'] = true;
                c = s[i];
                cnt = 0;
            }
            cnt++;
        }
        if (cnt % 2)
            can[c-'a'] = true;

        for (char c='a'; c<='z'; c++)
            if (can[c-'a'])
                cout << c;
        cout << "\n";
    }

    return 0;
}