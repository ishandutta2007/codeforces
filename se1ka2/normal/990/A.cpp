#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n % m == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << min(b * (n % m), a * (m - n % m)) << endl;
}