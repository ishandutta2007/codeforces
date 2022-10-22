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
        int a;
        cin >> a;
        int r = gcd(a, 180);
        if(r + a != 180) cout << 180 / r << endl;
        else cout << 360 / r << endl;
    }
}