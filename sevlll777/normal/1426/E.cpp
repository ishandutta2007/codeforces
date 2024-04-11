#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    int minn = min(a1, b1+b3)+min(a2,b1+b2)+min(a3,b2+b3);
    int maxx = min(a1, b2) + min(a2, b3) + min(a3, b1);
    cout << n-minn << ' ' << maxx << '\n';
}