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

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
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
*/

void solve() {
    int n;
    cin >> n;

    vector<li> a(n);
    li mx = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
//        mx = max(mx, a[i]);
        sum += a[i];
    }

//    sum -= mx;

    set<li> st(a.begin(), a.end());

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        li x, y;
        cin >> x >> y;

        auto it = st.lower_bound(x);

        li res = INF;

        if(it != st.end()) {
            res = min(res, max(0ll, y - sum + *it));
        }

        if(it != st.begin()) {
            it--;
            res = min(res, max(0ll, y - sum + *it) + x - *it);
        }

//        if(it == st.end())
//            res = max(0ll, x - mx) + max(0ll, y - sum);
//        else {
//            res = max(0ll, y - sum - mx + *it);
//            if(it != st.begin()) {
//                it--;
//                res = max(0ll, y - sum - mx + x);
//            }
////            cout <<  << '\n';
//        }

        cout << res << '\n';

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--) {
        solve();
    }
}