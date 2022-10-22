#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

void solve() {
    unsigned long long x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;

    unsigned long long d = min(p1, p2);

    p1 -= d;
    p2 -= d;

    if(p1 > 12) {
        cout << ">\n";
    } else if(p2 > 12) {
        cout << "<\n";
    } else {
        for(int i = 0; i < p1 && x1 <= x2; i++) {
            x1 *= 10;
        }

        for(int i = 0; i < p2 && x2 <= x1; i++) {
            x2 *= 10;
        }

        if(x1 == x2)
            cout << "=\n";
        else if(x1 < x2)
            cout << "<\n";
        else
            cout << ">\n";
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}