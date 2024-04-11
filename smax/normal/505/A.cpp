#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    for (int i=0; i<s.length(); i++)
        if (s[i] != s[s.length()-i-1])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string r = s;

    bool add = true;
    for (int i=0; i<s.length(); i++)
        if (s[i] != s[s.length()-i-1] && add) {
            add = false;
            s.insert(s.length()-i, 1, s[i]);
        }

    if (add) {
        s.insert(s.length() / 2, 1, s[s.length() / 2]);
        cout << s << "\n";
    } else if (check(s))
        cout << s << "\n";
    else {
        add = true;
        for (int i=r.length()-1; i>=0; i--)
            if (r[i] != r[r.length()-i-1]) {
                if (add) {
                    add = false;
                    r.insert(r.length()-i-1, 1, r[i]);
                } else {
                    cout << "NA\n";
                    return 0;
                }
            }
        cout << r << "\n";
    }

    return 0;
}