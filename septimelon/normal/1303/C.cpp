#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    string s, cl;
    cin >> s;
    cl = "################################################################################################################################################################################################################################";
    cl[27] = s[0];
    vector<bool> used(26, false);
    used[s[0] - 'a'] = true;
    int ci = 27;
    for (int i = 1; i < s.size(); ++i) {
        if (cl[ci - 1] == s[i]) {
            --ci;
        } else if (cl[ci + 1] == s[i]) {
            ++ci;
        } else if (used[s[i] - 'a']) {
            cout << "NO\n";
            return;
        } else if (cl[ci + 1] == '#') {
            cl[ci + 1] = s[i];
            used[s[i] - 'a'] = true;
            ++ci;
        } else if (cl[ci - 1] == '#') {
            cl[ci - 1] = s[i];
            used[s[i] - 'a'] = true;
            --ci;
        } else {
            cout << "NO\n";
            return;
        }
    }
    string clav("");
    for (int i = 0; i < cl.size(); ++i) {
        if (cl[i] != '#') {
            clav += cl[i];
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (!used[i]) {
            clav += ('a' + i);
        }
    }
    cout << "YES\n" << clav << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}