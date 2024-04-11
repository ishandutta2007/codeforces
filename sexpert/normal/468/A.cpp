#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n <= 3) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if(n % 2) {
        for(int k = 6; k <= n; k += 2)
            cout << k + 1 << " - " << k << " = 1\n";
        for(int i = 1; i < (n - 5)/2; i++)
            cout << "1 * 1 = 1\n";
        cout << "5 + 4 = 9\n9 + 3 = 12\n12 * 2 = 24\n24 * 1 = 24\n";
        if(n > 5)
            cout << "24 * 1 = 24\n"; 
    }
    else {
        for(int k = 5; k <= n; k += 2)
            cout << k + 1 << " - " << k << " = 1\n";
        for(int i = 1; i < (n - 4)/2; i++)
            cout << "1 * 1 = 1\n";
        cout << "4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24\n";
        if(n > 4)
            cout << "24 * 1 = 24\n";
    }
}