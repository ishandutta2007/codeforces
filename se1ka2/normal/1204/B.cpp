#include <iostream>
using namespace std;
typedef long long ll;

ll power(ll x, ll n){
    ll res = 1;
    for(int i = 0; i < n; i++) res *= x;
    return res;
}

int main()
{
    ll n, l, r;
    cin >> n >> l >> r;
    cout << power(2, l) - 1 + (n - l) << " " << power(2, r) - 1 + power(2, r - 1) * (n - r) << endl;
}