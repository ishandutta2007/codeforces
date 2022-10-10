#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        int n =  180/__gcd(180, a);
        if(n*a/180 > n - 2)
            n *= 2;
        cout << n << endl;
    }    
}