#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8001;
const ll md = 1e9 + 7;

ll p[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ll x, y = 0;
    cin >> x;

    y = (x / 10000) * 10000 + (x / 100 % 10) * 1000 + (x % 10) * 100 + (x / 10 % 10) * 10 + (x / 1000 % 10);
    //cerr << y << "\n";
    ll st = 1;
    for (int i = 0; i < 5; i++) {
        st = (st * y) % 100000;
    }
    int ss = st;
    printf("%05d", ss);


    return 0;
}