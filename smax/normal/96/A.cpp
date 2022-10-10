#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    
    int mx = 0, n = 1;
    for (int i=1; i<s.length(); i++) {
        if (s[i] != s[i-1]) {
            mx = max(mx, n);
            n = 1;
        } else
            n++;
    }
    if (mx >= 7 || n >= 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}