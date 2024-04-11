#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a + b + c + d == 0) {
        cout << 1 << endl;
        return 0;
    }
    if(a == 0 && c > 0) {
        cout << 0 << endl;
        return 0;
    }
    if(d != a) {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
}