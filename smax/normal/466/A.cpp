#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (b >= m * a)
        cout << n * a << endl;
    else
        cout << (n % m == 0 ? n / m * b : n / m * b + min(n % m * a, b)) << endl;
    
    return 0;
}