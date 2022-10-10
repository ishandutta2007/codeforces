#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char c = 'z';
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        c = min(c, s[i]);
        cout << (s[i] == c ? "Mike" : "Ann") << "\n";
    }

    return 0;
}