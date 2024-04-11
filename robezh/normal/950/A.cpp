#include <bits/stdc++.h>
using namespace std;

int l,r,a;

int main() {
    int l, r, a;
    cin >> l >> r >> a;
    int res = (l + r + a) / 2 * 2;
    res = min((l+a)*2, res);
    res = min((r+a)*2, res);
    cout << res;
}