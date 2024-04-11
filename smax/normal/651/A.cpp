#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, b, ret = 0;
    cin >> a >> b;
    if (a < 2 && b < 2) {
        cout << 0 << endl;
        return 0;
    }
    while (a > 2 || b > 2) {
        if (a < b) {
            a += b % 2 == 0 ? b / 2 - 1 : b / 2;
            ret += b % 2 == 0 ? b / 2 - 1 : b / 2;
            b = b % 2 == 0 ? 2 : 1;
        } else {
            b += a % 2 == 0 ? a / 2 - 1 : a / 2;
            ret += a % 2 == 0 ? a / 2 - 1 : a / 2;
            a = a % 2 == 0 ? 2 : 1;
        }
    }
    cout << ret + 1 << endl;
    
    return 0;
}