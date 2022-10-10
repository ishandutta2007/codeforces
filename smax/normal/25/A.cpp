#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a, b, c;
    cin >> n >> a >> b;
    if (a % 2 == b % 2)
        for (int i=3; i<=n; i++) {
            cin >> c;
            if (c % 2 != a % 2)
                cout << i << endl;
        }
    else {
        cin >> c;
        cout << (a % 2 == c % 2 ? 2 : 1) << endl;
    }
    
    return 0;
}