#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    for(int d = 2; d * d <= x; d++) {
        if(x % d == 0) {
            cout << d << x / d << '\n';
            return 0;
        }
    }
}