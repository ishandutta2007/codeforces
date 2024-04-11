#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k = 0, t = 1, a[100] = {0};
    cin >> n;
    while (n > 0) {
        int b = n % 10;
        k = max(k, b);
        for (int i=0; i<b; i++)
            a[i] += t;
        t *= 10;
        n /= 10;
    }
    
    cout << k << endl;
    for (int i=0; i<k; i++)
        cout << a[i] << " ";
    cout << endl;
    
    return 0;
}