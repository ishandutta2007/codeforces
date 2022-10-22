#include <algorithm>
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
        int n;
        cin >> n;
        for(int i = 2; i < n; i++){
            if(gcd(n - 1 - i, i) == 1){
                cout << n - 1 - i << " " << i << " " << 1 << endl;
                break;
            }
        }
    }
}