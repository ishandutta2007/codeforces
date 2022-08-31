#include <iostream>

using namespace std;

int L, v, l, r;

int f(int k) {
    if (k == 0) return 0;
    return k / v;
}

int main(){
    int t; cin >> t;
    while (t--) {
        cin >> L >> v >> l >> r;
        cout << f(L) - f(r) + f(l-1) << endl;
    }

    return 0;
}