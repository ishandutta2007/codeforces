#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n >= 3 || (n == 2 && s[1] > s[0]))
            cout << "YES\n2\n" << s[0] << " " << s.substr(1) << '\n';
        else
            cout << "NO\n";
    }
}