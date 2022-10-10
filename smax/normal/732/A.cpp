#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int k, r;
    cin >> k >> r;
    
    int i = 1;
    while ((i * k - r) % 10 != 0 && i * k % 10 != 0)
        i++;
    cout << i << endl;
    
    return 0;
}