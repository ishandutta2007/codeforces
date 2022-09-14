#include <bits/stdc++.h>

using namespace std;

int a[10][2];

int main(){
#ifdef FLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, t, x;
    cin >> n;
    string s;
    for (int i = 0; i < 10; i++)
        a[i][1] = 1;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        for (int j = 0; j < 10; j++, t /= 2) {
            x = t % 2;
            if (s[0] == '^') {
                a[j][0] ^= x;
                a[j][1] ^= x;
            }
            else if (s[0] == '|') {
                a[j][0] |= x;
                a[j][1] |= x;
            }
            else {
                a[j][0] &= x;
                a[j][1] &= x;
            }
        }
    }
    int d = 0, e = 0, f = 0;
    for (int i = 0; i < 10; i++) {
        x = 1 << i;
        if (a[i][0] && !a[i][1])
            d |= x;
        if (a[i][0] && a[i][1])
            e |= x;
        if (a[i][0] || a[i][1])
            f |= x;
    }
    cout << "3\n^ " << d << "\n| " << e << "\n& " << f;
}