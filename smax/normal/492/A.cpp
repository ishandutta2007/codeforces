#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, ret = 0;
    cin >> n;
    while (n - (ret + 1) * (ret + 2) / 2 >= 0) {
        n -= (ret + 1) * (ret + 2) / 2;
        ret++;
    }
    cout << ret << endl;
    
    return 0;
}