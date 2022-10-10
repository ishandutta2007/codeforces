#include <bits/stdc++.h>
using namespace std;

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

        bool ok = true;
        for (int i=0; i<s.length() && ok; i++) {
            if (s[i] == '?') {
                unordered_set<char> st;
                if (i > 0) st.insert(s[i-1]);
                if (i < s.length() - 1) st.insert(s[i+1]);
                for (char c='a'; c<='c'; c++)
                    if (!st.count(c)) {
                        s[i] = c;
                        break;
                    }
            } else
                ok &= ((i == 0 || s[i-1] != s[i]) && (i == s.length() - 1 || s[i+1] != s[i]));
        }

        cout << (ok ? s : "-1") << "\n";
    }

    return 0;
}