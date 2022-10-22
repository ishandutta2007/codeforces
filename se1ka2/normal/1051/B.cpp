#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    for(ll i = l; i < r; i += 2){
        cout << i << " " << i + 1 << endl;
    }
}