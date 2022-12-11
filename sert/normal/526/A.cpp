#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
int n;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    cin >> s;
    for (int len = 1; len <= n; len++)
        for (int pos = 0; pos < n; pos++) {
            if (pos + len * 4 >= n) continue;
            if (s[pos] == '*' && s[pos + len] == '*' && s[pos + len * 2] == '*' && s[pos + len * 3] == '*' && s[pos + len * 4] == '*') {
                cout << "yes\n";
                return 0;
            }
        }
    cout << "no\n";
    return 0;
}