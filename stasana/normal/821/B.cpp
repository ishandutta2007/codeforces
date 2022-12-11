#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main(){
    ll k, b;
    cin >> k >> b;
    ll x, y;
    y = b;
    x = k * b;
    ll res = 0;
    for(ll i = 0, j; i < y; ++i){
        j = (b - i) * k;
        res = max(res,(i+1) * (j + 1) * (i + j) / 2);
    }
    cout << res;
    return 0;
}