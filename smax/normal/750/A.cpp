#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    int i = 0;
    while (5 * i * (i + 1) / 2 + k <= 240 && i <= n)
        i++;
    
    cout << i-1 << endl;
    
    return 0;
}