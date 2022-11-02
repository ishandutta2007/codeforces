#include<bits/stdc++.h>
using namespace std;

int main() {
    long long l, r, L, R, k;
    cin >> l >> r >> L >> R >> k;
    l = max(l, L);
    r = min(r, R);
    if(l > r) puts("0");
    else cout << (r - l + (k < l || r < k)) << endl;
}