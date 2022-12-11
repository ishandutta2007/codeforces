#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
string s, t;
bool u[N];
int p, ans;
int main() {
    cin >> s >> t;
    for (int i = 0; i + t.length() <= s.length(); i++) {
        for (int j = 0; !u[i] && j < t.length(); j++)
            if (s[i + j] != t[j])
                u[i] = true;
    }
    p = 0;
    while (p < s.length()) {
        if (!u[p] && p + t.length() <= s.length()) {
            ans++;
            p += t.length();
        } else {
            p++;
        }
    }
    cout << ans;
}