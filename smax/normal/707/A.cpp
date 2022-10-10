#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n*m; i++) {
        char c;
        cin >> c;
        if (c == 'C' || c == 'M' || c == 'Y') {
            cout << "#Color" << endl;
            return 0;
        }
    }
    cout << "#Black&White" << endl;
    
    return 0;
}