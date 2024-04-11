#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 1e5 + 13;
const int LOGN = 30;

int M;

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

mt19937 rnd(45567);

int a[N];
int dv[N];

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        dv[i] = a[i] + 1;
    }

    int ans = INF;
    for(int x = 0; x <= 3013; x++) {
//    for(int x = 0; x <= 16; x++) {
        bool fl = false;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            while(dv[i] > 0 && a[i] / dv[i] < x)
                dv[i]--;

            if(dv[i] == 0/* || dv[i] > k*/)
                fl = true;
            else
                mx = max(mx, a[i] / min(k, dv[i]));
        }

//        cout << "x = " << x << endl;
//        for(int i = 0; i < n; i++)
//            cout << dv[i] << ' ';
//        cout << endl;

        if(!fl)
            ans = min(ans, mx - x);
    }

    cout << ans << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}