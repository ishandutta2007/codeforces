#include <iostream>
#define LL long long

using namespace std;

LL f(LL x, LL p) {
    return (x - p % x) % x;
}

int main(){
    int t; cin >> t;
    while (t--) {
        LL p, a, b, c;
        cin >> p >> a >> b >> c;
        LL r = 2e18;
        r = min(r, f(a, p));
        r = min(r, f(b, p));
        r = min(r, f(c, p));
        cout << r << "\n";
    }

    return 0;
}