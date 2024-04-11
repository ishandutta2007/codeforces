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
        int r, b, k;
        cin >> r >> b >> k;
        if(r < b) swap(r, b);
        int g = gcd(r, b);
        r /= g;
        b /= g;
        if(r == 1){
            cout << "OBEY" << endl;
            continue;
        }
        if((r - 2) / b + 1 < k) cout << "OBEY" << endl;
        else cout << "REBEL" << endl;
    }
}