#include <bits/stdc++.h>
using namespace std;

int main() {
    string c, s[5];
    cin >> c;
    for(int i = 0; i < 5; i++)
        cin >> s[i];
    for(int i = 0; i < 5; i++) {
        if(c[0] == s[i][0] || c[1] == s[i][1]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}