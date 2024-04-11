#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    cout << (char)toupper(s[0]) << s.substr(1) << endl;
    
    return 0;
}