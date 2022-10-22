#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    k++;
    if(k <= n) cout << k << " " << 1 << endl;
    else{
        ll r = (k - n - 1) / ((m - 1) * 2);
        if((k - n - 1) % ((m - 1) * 2) < m - 1){
            cout << n - r * 2 << " " << (k - n - 1) % (m - 1) + 2 << endl;
        }
        else{
            cout << n - (r * 2 + 1) << " " << m - (k - n - 1) % (m - 1) << endl;
        }
    }
}