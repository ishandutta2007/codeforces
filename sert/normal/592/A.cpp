#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[10];
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    for (int i = 0; i < 8; i++)
        cin >> s[i];
    int w = 100, b = 100;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[j][i] == 'B')
                break;
            if (s[j][i] == 'W')
                w = min(w, j);
        }
        for (int j = 7; j >= 0; j--) {
            if (s[j][i] == 'W')
                break;
            if (s[j][i] == 'B')
                b = min(b, 7 - j);
        }
    }

    cout << (w <= b ? 'A' : 'B');


    return 0;
}