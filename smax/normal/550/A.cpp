#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int i = 0;
    bool ab = false, ba = false;
    string s;
    cin >> s;
    
    while (i < s.length() - 1) {
        if (!ab && s.substr(i, 2) == "AB") {
            ab = true;
            i++;
        } else if (!ba && s.substr(i, 2) == "BA") {
            ba = true;
            i++;
        }
        i++;
    }
    if (ab && ba) {
        cout << "YES" << endl;
        return 0;
    }
    
    i = s.length() - 1;
    ab = false;
    ba = false;
    while (i > 0) {
        if (!ab && s.substr(i-1, 2) == "AB") {
            ab = true;
            i--;
        } else if (!ba && s.substr(i-1, 2) == "BA") {
            ba = true;
            i--;
        }
        i--;
    }
    
    if (ab && ba)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}