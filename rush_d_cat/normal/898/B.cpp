#include <iostream>
using namespace std;

long long n, a, b;

// int 4e9

int main() {
    cin >> n >> a >> b;
    // b * y = n - a*x
    for (long long x = 0; x * a <= n; x ++) {
        if ( (n - a*x) % b == 0 ) {
            cout << "YES" << endl; 
            cout << x  << " " << ((n-a*x)/b) << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}