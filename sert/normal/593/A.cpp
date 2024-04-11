#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100][100], b;
int n, ch1, ch2, c;
string s;
bool fail;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    while (n--) {
        cin >> s;
        fail = false;
        ch1 = ch2 = -1;
        for (int i = 0; i < s.length() && !fail; i++) {
            c = s[i] - 'a';
            if (c == ch1 || c == ch2)
                continue;
            if (ch1 == -1)
                ch1 = c;
            else if (ch2 == -1)
                ch2 = c;
            else
                fail = true;
        }
        if (!fail) {
            if (ch2 != -1) {
                a[ch1][ch2] += s.length();
                a[ch2][ch1] += s.length();
            } else {
                for (int i = 0; i < 26; i++) {
                    a[ch1][i] += s.length();
                    a[i][ch1] += s.length();
                }
                a[ch1][ch1] -= s.length();
            }
        }
    }

    int res = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            res = max(res, a[i][j]);
    cout << res;

    return 0;
}