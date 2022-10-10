#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll xo, su;
    cin >> xo >> su;
    if(xo > su || (xo%2 != su%2)) {
        cout << "-1\n";
        return 0;
    }
    if(xo == su) {
        if(xo == 0) {
            cout << "0\n";
            return 0;
        }
        cout << "1\n";
        cout << xo << '\n';
        return 0;
    }
    ll nd = (su - xo)/2;
    if(nd & xo) {
        cout << "3\n";
        cout << xo << " " << nd << " " << nd << '\n';
        return 0;
    }
    ll u = 0, v = 0;
    for(ll b = 0; b < 60; b++) {
        if(nd & (1LL << b)) {
            u += (1LL << b);
            v += (1LL << b);
        }
        if(xo & (1LL << b))
            u += (1LL << b);
    }
    cout << "2\n";
    cout << u << " " << v << '\n';
}