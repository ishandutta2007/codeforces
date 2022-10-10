#include <bits/stdc++.h>
using namespace std;

unordered_set<char> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string good, pattern;
    int n;
    cin >> good >> pattern >> n;
    for (char c : good)
        st.insert(c);

    while (n--) {
        string s;
        cin >> s;

        int i = 0, j = 0;
        bool ok = true;
        while (j < pattern.length() && ok) {
            if (pattern[j] == '?') {
                if (i >= s.length() || !st.count(s[i]))
                    ok = false;
                i++;
            } else if (pattern[j] == '*') {
                while (i < s.length() && !st.count(s[i]) && s.length() - i > pattern.length() - j - 1)
                    i++;
            } else {
                if (i >= s.length() || pattern[j] != s[i])
                    ok = false;
                i++;
            }
            j++;
        }
        if (i < s.length() || j < pattern.length())
            ok = false;

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}