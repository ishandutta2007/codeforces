#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll x, y, k;
        cin >> x >> y >> k;
        ll s = k + k * y - 1;
        cout << (s - 1) / (x - 1) + 1 + k << endl;
    }
}