#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

void solve() {
    int a, b, c, r1;
    cin >> a >> b >> c >> r1;

    if(a > b)
        swap(a, b);

    int l = c - r1, r = c + r1;

    int t = b - a;

    int lf = max(a, l), rg = min(b, r);
    cout << t - max(0, rg - lf) << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}