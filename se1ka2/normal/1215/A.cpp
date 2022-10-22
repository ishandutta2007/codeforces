#include <iostream>
using namespace std;

int main()
{
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    cout << max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1)) << endl;
    if(k1 < k2){
        if(k1 * a1 > n) cout << n / k1 << endl;
        else cout << a1 + (n - a1 * k1) / k2 << endl;
    }
    else{
        if(k2 * a2 > n) cout << n / k2 << endl;
        else cout << a2 + (n - a2 * k2) / k1 << endl;
    }
}