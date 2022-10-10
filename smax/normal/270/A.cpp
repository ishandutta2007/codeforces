#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int a;
        cin >> a;
        int s = 3;
        while (180 * (s-2) / (double) s < a)
            s++;
        if (180 * (s-2) / s * s == 180 * (s-2) && 180 * (s-2) / s == a)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}