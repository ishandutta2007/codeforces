#include <bits/stdc++.h>
using namespace std;
int n, len;
string s, f = "1";
bool ok;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "0") {
            cout << 0;
            return 0;
        }
        ok = true;
        if (s[0] != '1') ok = false;
        for (int i = 1; i < s.length(); i++)
            if (s[i] != '0') ok = false;
        if (ok) len += s.length() - 1;
        else f = s;
    }
    cout << f;
    for (int i = 0; i < len; i++)
        cout << "0";
}