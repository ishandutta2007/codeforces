#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using li = long long;

void solve() {
    int a, b;
    cin >> a >> b;

    if(a > b)
        swap(a, b);

    bool ans;

    if(a == 1) {
        ans = true;
    } else if(__gcd(a, b) == 1) {
        ans = true;
    } else {
        ans = false;
    }

    cout << (ans ? "Finite" : "Infinite") << endl;

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}