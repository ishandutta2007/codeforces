#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        cout << (d < l ? d : d*(r/d + 1)) << endl;
    }
}