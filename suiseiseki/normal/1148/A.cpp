#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll n, a, b, c;
    cin >> a >> b >> c;
    if(a == b) cout << a + b + 2 * c;
    if(a > b) {
        cout << 2 * b + 2 * c + 1 << '\n';
    }
    else if(b > a) {
        ll ans = 0;
        ans = 2 * a + 1 + 2 * c;
        cout << ans << '\n';
    }
    return 0;
}