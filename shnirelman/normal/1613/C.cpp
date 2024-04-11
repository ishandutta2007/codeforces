#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
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
    int n;
    li h;
    cin >> n >> h;

    vector<li> a(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = INF64;

    li l = 0, r = h + 1;
    while(r - l > 1) {
        li m = (l + r) / 2;

        li res = 0;
        for(int i = 0; i < n; i++) {
            res += min(m, a[i + 1] - a[i]);
        }

        if(res >= h)
            r = m;
        else
            l = m;
    }

    cout << r << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}