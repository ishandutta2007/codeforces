//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
using pci = pair<char, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 7;//998244353;
const int B = 350;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, li k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

/*
*/


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();

    int k;
    cin >> k;

    cout << mul(6, pow2(4, (1ll << k) - 2)) << endl;

//    int f = 6, g = 1;
//    for(int i = 1; i <= k; i++) {
//        g = mul(mul(g, g), 16);
//    }
//
//    cout << mul(g, 6) << endl;
}