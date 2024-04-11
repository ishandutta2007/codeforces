#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll a, b, n;
        cin >> a >> b >> n;
        if(n % 3 == 2) cout << (a ^ b) << endl;
        if(n % 3 == 0) cout << a << endl;
        if(n % 3 == 1) cout << b << endl;
    }
}