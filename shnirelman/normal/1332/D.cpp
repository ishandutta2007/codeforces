#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

const int N = 2e5 + 13;

void solve() {
    int k;
    cin >> k;

    if(k == 0) {
        cout << 1 << ' ' << 1 << endl << 1 << endl;
        return;
    }

    cout << 3 << ' ' << 3 << endl;
    cout << (1 << 18) - 1 << ' ' << k << ' ' << 0 << endl;
    cout << (1 << 17) << ' ' << (1 << 18) - 1 << ' ' << 0 << endl;
    cout << 0 << ' ' << k << ' ' << k << endl;
}

int main() {
    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}