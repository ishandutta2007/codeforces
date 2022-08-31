#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int r, c, k = 1;
        while (n > k * k) k++;
        int m = n - (k-1)*(k-1);
        if (m <= k) r = m; else r = k;
        if (m <= k) c = k; else c = k*k-n+1;
        cout << r << " " << c << "\n";
    }

    return 0;
}