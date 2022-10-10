#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int n;
        cin >> n;
        if (n == 1 || n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
            cout << -1 << endl;
        else if (n % 4 == 0)
            cout << n / 4 << endl;
        else if (n % 4 == 1)
            cout << (n - 9) / 4 + 1 << endl;
        else if (n % 4 == 2)
            cout << (n - 6) / 4 + 1 << endl;
        else
            cout << (n - 15) / 4 + 2 << endl;
    }
    
    return 0;
}