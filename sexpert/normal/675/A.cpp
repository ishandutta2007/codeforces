#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int diff = b - a;
    if(c == 0) {
        cout << (a == b ? "YES" : "NO") << endl;
        return 0;
    }
    if(abs(diff) % abs(c)) {
        cout << "NO" << endl;
        return 0;
    }
    if(diff/c < 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}