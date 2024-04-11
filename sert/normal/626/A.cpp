#include <bits/stdc++.h>
using namespace std;
int n, u, l, ans;
string s;
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
        u = l = 0;
        for (int p = i; p <= j; p++) {
            if (s[p] == 'U') u++;
            if (s[p] == 'D') u--;
            if (s[p] == 'L') l++;
            if (s[p] == 'R') l--;
        }
        if (u == 0 && l == 0)
            ans++;
    }
    cout << ans;
}