#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 998244353;
const int g = 3;
const int ALF = (1 << 20) - 3;
const int N = (1 << 23) + 13;
//const int N = 20 + 13;
const int K = 2e5 + 13;
//const int K = 20 + 13;
const int LOGN = 23;
const ld PI = acos(-1);
const ld eps = 1e-4;
const int S = 1007;
//const int B = 100;

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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int mx = 0, mn = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > a[mx])
            mx = i;

        if(a[i] < a[mn])
            mn = i;
    }

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++) {
        if(b[i] < a[i]) {
            cout << "NO" << endl;
            return;
        }

        if(a[i] != b[i] && b[i] > b[(i + 1) % n] + 1) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

//    if(a[mn] == a[mx]) {
//        for(int i = 0; i < n; i++) {
//            if(b[i] < a[i]) {
//                cout << "NO" << endl;
//                return;
//            }
//
//            if(b[i] > b[(i + 1) % n] + 1) {
//                cout << "NO" << endl;
//                return;
//            }
//        }
//
//        cout << "YES" << endl;
//    }
//
//    for(int i = 0; i < n; i++)
//        if(a[mx] == a[i] && a[(i + 1) % n])
//
//    if(a[mx] != b[mx]) {
//        cout << "NO" << endl;
//        return;
//    }
//
//    for(int j = n - 1; j > 0; j--) {
//        int i = (j + mx) % n;
//        int i1 = (i + 1) % n;
//
//        if(a[i] == b[i])
//            continue;
//
//        if(a[i] > b[i] || b[i] > b[i1]) {
//            cout << "NO" << endl;
//            return;
//        }
//
//
//    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}