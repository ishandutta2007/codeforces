#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i = 1, a[1000];
    cin >> n;
    if (n == 2) {
        cout << 1 << endl << 2 << endl;
        return 0;
    }
    a[0] = 1;
    n--;
    while (n > 0) {
        if (n - a[i-1] - 1 > a[i-1] + 1) {
            a[i] = a[i-1] + 1;
            n -= a[i-1] + 1;
        } else {
            a[i] = n;
            n = 0;
        }
        i++;
    }
    cout << i << endl;
    for (int j=0; j<i; j++)
        cout << a[j] << " ";
    cout << endl;
    
    return 0;
}