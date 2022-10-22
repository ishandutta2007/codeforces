#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int k;
    cin >> k;
    while(k--){
        ll n, x, t;
        cin >> n >> x >> t;
        ll l = min(n, t / x);
        cout << l * (n - l) + l * (l - 1) / 2 << endl;
    }
}