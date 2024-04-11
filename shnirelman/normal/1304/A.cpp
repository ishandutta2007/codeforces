#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

void solve() {
    int x,y, a, b;
    cin >> x >> y >> a >> b;

    if((y - x) % (a + b) == 0)
        cout << (y - x) / (a + b) << endl;
    else
        cout << - 1 << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int n;
//    cin >> n;

    int t;
    cin >> t;
    while(t--)
        solve();
}