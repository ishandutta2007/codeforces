#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, xT = 0, yT = 0, zT = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        xT += x;
        yT += y;
        zT += z;
    }
    
    if (xT == 0 && yT == 0 && zT == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}