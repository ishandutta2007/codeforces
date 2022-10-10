#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    bool y = false;
    for (int i=2; i<=n; i++) {
        bool isLucky = true;
        for (char c : to_string(i))
            if (c != '4' && c != '7') {
                isLucky = false;
                break;
            }
        if (isLucky)
            if (n % i == 0) {
                y = true;
                break;
            }
    }
    
    if (y)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}