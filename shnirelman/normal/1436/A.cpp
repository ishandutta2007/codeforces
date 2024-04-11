#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 40;

int sum(int a, int b) {
    int res = a + b;
    if(res >= M)
        res -= M;
    return res;
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

    if(k & 1)
        return mul(n, mul(pw, pw));
    else
        return mul(pw, pw);
}


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    li s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    cout << (s == m ? "YES" : "NO") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}