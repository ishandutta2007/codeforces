#include <iostream>
using namespace std;

int gcd(int n, int m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int a, b;
        cin >> a >> b;
        if(gcd(a, b) == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }
}