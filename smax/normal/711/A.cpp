#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    string s[1000];
    bool yes = false;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        if (!yes && s[i][0] == 'O' && s[i][1] == 'O') {
            s[i][0] = s[i][1] = '+';
            yes = true;
        } else if (!yes && s[i][3] == 'O' && s[i][4] == 'O') {
            s[i][3] = s[i][4] = '+';
            yes = true;
        }
    }
    if (!yes)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i=0; i<n; i++)
            cout << s[i] << endl;
    }
    
    return 0;
}