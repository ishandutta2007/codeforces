#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n;
    int ret = 0;
    cin >> n;
    while (n > 0) {
        if (n % 10 == 4 || n % 10 == 7)
            ret++;
        n /= 10;
    }
    
    bool isLucky = ret > 0;
    while (ret > 0) {
        if (ret % 10 != 4 && ret % 10 != 7) {
            isLucky = false;
            break;
        }
        ret /= 10;
    }
    
    if (isLucky)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}