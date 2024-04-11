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
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 998244353;
const int B = 300;
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

/*
3 5 0 0 5
1 3 1

*/

void solve() {
    int a, b;
    cin >> a >> b;

    int n = (a + b) / 2;
    int m = a + b - n;

    int lx = max(0, a - m);
    int rx = min(a, n);

    set<int> st;
    for(int x = lx; x <= rx; x++) {
        int y = m + x - a;

        if(max(0, b - n) <= y && y <= min(b, m)) {
            st.insert(x + y);
        }
    }

    lx = max(0, a - n);
    rx = min(a, m);

    for(int x = lx; x <= rx; x++) {
        int y = n + x - a;

        if(max(0, b - m) <= y && y <= min(b, n)) {
            st.insert(x + y);
        }
    }

    cout << st.size() << endl;
    for(auto k : st)
        cout << k << ' ';
    cout << endl;

//    int l = max(0, a - m) + max(0, b - n);
//    int r = min(a, n) + min(b, m);
//
//    cout << r - l + 1 << endl;
//
//    vector<int> res;
//    for(int i = 0; i <= a + b; i++) {
//
//    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}