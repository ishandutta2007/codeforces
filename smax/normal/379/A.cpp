#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, ret = 0;
    cin >> a >> b;
    
    while (a / b > 0) {
        ret += (a / b) * b;
        a += a / b - (a / b) * b;
    }
    
    cout << ret + a << endl;
    
    return 0;
}