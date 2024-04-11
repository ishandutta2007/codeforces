#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    bool ok = false;
    int pw = 1;
    for (int i=0; i<n; i++) {
        pw *= 2;
        if (pw > m) {
        ok = true;
        break;
    }
    }
    
    cout << m % pw << "\n";
}