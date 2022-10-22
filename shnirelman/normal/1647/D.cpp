#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

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

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

/*
*/

bool isp(int x) {
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}

int min_div(int x) {
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return i;
    return -1;
}

void solve() {
    int x, d;
    cin >> x >> d;

    int cnt = 0;
    while(x % d == 0) {
        cnt++;
        x /= d;
    }

//    cout << x << ' ' << cnt << endl;

    if(cnt < 2) {
        cout << "NO\n";
        return;
    }
//cout << x << ' ' << cnt << endl;
    if(!isp(x)) {
        cout << "YES\n";
        return;
    }

    if(isp(d) || cnt == 2) {
        cout << "NO\n";
        return;
    }

    if(cnt > 3) {
       cout << "YES\n";
        return;
    }
//cout << x << ' ' << cnt << endl;
//    int y = min_div(d);

    for(int i = 2; i * i <= d; i++)
        if(d % i == 0) {
            if(x * 1ll * i % d != 0 || x * 1ll * (d / i) % d != 0) {
                cout << "YES\n";
                return;
            }
        }

    cout << "NO\n";
//    if(cnt == 2 && x * 1ll * y % d == 0)
//        cout << "NO\n";
//    else
//        cout << "YES\n";
//    if(isp(x) && (isp(d) || cnt == 2))
////    if(cnt < 2 || isp(x))
//        cout << "NO\n";
//    else
//        cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}