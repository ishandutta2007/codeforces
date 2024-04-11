#include <iostream>
using namespace std;

int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        cout << 100 / gcd(100, k) << endl;
    }
}