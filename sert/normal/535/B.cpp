#include <bits/stdc++.h>

using namespace std;

int n, ans, a, b;
string s, t;

int main() {
    cin >> t;
    s = "4";
    n = 1;
    while (s != t) {
        n++;
        b = s.length() - 1;
        while (s[b] == '7') {
            s[b] = '4';
            b--;
            if (b == -1)
                break;
        }
        if (b == -1) s = "4" + s;
        else s[b] = '7';

    }
    cout << n;
    return 0;
}