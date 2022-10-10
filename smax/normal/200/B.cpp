#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double total = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        total += p;
    }
    cout << total / n << endl;
    
    return 0;
}