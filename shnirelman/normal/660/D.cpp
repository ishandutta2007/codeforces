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
const int N = 3e5 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
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

/*
*/

pii a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    map<pii, int> mp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            mp[{a[i].f + a[j].f, a[i].s + a[j].s}]++;
        }
    }

    li ans = 0;
    for(auto p : mp)
        ans += p.s * 1ll * (p.s - 1) / 2;

    cout << ans << endl;
}