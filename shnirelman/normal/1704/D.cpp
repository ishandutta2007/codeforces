#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int M = 1e9 + 7;
//const int M = 32768;
const int N = 5e5 + 13;
const int LOGN = 20;

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

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(54787);

/*
*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<li>> a(n, vector<li> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int k = -1;

    vector<li> bal(n, 0);
    map<li, int> mp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bal[i] += a[i][j] * j;
        }
        mp[bal[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(mp[bal[i]] == 1) {
            k = i;
            li x = (i == 0 ? bal[1] : bal[0]);
            cout << i + 1 << ' ' << bal[i] - x << endl;
            return;
        }
    }
//    li sum = 0;
//    for(int i = 0; i < m; i++)
//        sum += a[0][i];
//
//    vector<int> b(m, -1);
//    vector<int> x(n, 0);
//    {
//        int mn = INF;
//        for(int i = 0; i < n; i++)
//            mn = min(mn, a[i][0]);
//
//        b[0] = mn;
//
//        for(int i = 0; i < n; i++)
//            x[i] = a[i][0] - b[0];
//    }
//
//    for(int j = 1; j < m; j++) {
//        int mn = INF;
//        for(int i = 0; i < n; i++)
//            mn = min(mn, a[i][j] + x[i]);
//
//        b[j] = mn;
//
//        for(int i = 0; i < n; i++)
//            x[i] =
//    }
//
//    for(int i = 0; i < n; i++) {
//        li res = 0;
//        for(int j = 0; j < m - 1; j++)
//            res += a[i][j + 1] - a[i][j];
//
//        if(res != 0) {
//            k = i;
//        }
//
//        cout << i << ' ' << res << endl;
//    }

//    for(int j = 0; j < m; j++) {
//        int mn = 0, mx = 0;
//        for(int i = 0; i < n; i++) {
//            if(a[i][j] < a[mn][j])
//                mn = i;
//            if(a[i][j] > a[mx][j])
//                mx = j;
//        }
//
//        if(a[mn][j] != a[mx][j]) {
//            k = mn;
//            break;
//        }
//    }

//    cout << k + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}