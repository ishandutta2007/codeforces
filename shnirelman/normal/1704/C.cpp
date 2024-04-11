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

    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        b[i] = (i == m - 1 ? n + a[0] - a[m - 1] - 1 : a[i + 1] - a[i] - 1);
    }

//    for(int x : b)
//        cout << x << ' ';
//    cout << endl;

    sort(b.rbegin(), b.rend());
//
//    for(int x : b)
//        cout << x << ' ';
//    cout << endl;

    int ans = 0;
    int t = 0;
    for(int i = 0; i < m; i++) {
        if(t * 2 < b[i]) {
            ans++;
            t++;
            if(t * 2 - 1 < b[i]) {
//                ans++;
                ans += b[i] - t * 2;
                t++;
            }
        }
    }

    cout << n - ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}