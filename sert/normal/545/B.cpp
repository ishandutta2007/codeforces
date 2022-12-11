#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 7;

string s, t;
int kol;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) if (s[i] != t[i]) kol++;
    if (kol % 2) {cout << "impossible\n"; return 0;}
    kol /= 2;
    for (int i = 0; i < s.length() && kol; i++)
    if (s[i] != t[i]) {
        s[i] = t[i];
        kol--;
    }
    cout << s;
    return 0;
}