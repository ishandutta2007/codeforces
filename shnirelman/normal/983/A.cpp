#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        li p, q, b;
        cin >> p >> q >> b;

        li g = __gcd(p, q);
        p /= g;
        q /= g;

        g = __gcd(q, b);
        while(g > 1) {
            while(q % g == 0)
                q /= g;
            g = __gcd(q, g);
        }

        cout << (q > 1 ? "Infinite\n" : "Finite\n");
    }
}