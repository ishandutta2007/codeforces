//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int M = 998244353;
const ld eps = 1e-6;
const int B = 100;
const int K = 400;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    vector<pii> v;
    for(int i = 1; i <= b; i++) {
        for(int j = 1; j <= b; j++) {
            if(i * i + j * j == b * b) {
                v.emplace_back(i, j);
            }
        }
    }

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= a; j++) {
            if(i * i + j * j == a * a) {
                for(auto p : v) {
                    int x = i + p.f;
                    int y = p.s;

                    int dx = x;
                    int dy = y - j;

                    if(y != j && (a * a + b * b) == (dx * dx + dy * dy)) {
                        cout << "YES" << endl;
                        cout << i << ' ' << 0 << endl;
                        cout << 0 << ' ' << j << endl;
                        cout << x << ' ' << y << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
}