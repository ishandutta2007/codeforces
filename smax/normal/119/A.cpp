#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, b, n;
    cin >> a >> b >> n;
    
    bool simonTurn = true;
    while (simonTurn && __gcd(a, n) <= n || !simonTurn && __gcd(b, n) <= n) {
        if (simonTurn)
            n -= __gcd(a, n);
        else
            n -= __gcd(b, n);
        simonTurn = !simonTurn;
    }
    
    cout << simonTurn << endl;
    
    return 0;
}