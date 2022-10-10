#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    cout << max(n, max(n / 10, n % 10 + n / 10 - n / 10 % 10)) << endl;
    
    return 0;
}