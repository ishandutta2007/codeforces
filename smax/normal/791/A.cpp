#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, t = 0;
    cin >> a >> b;
    while (a <= b) {
        a *= 3;
        b *= 2;
        t++;
    }
    cout << t << endl;
    
    return 0;
}