#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
//const int M = 998244353;
const int M = 1e9 + 7;
const int g = 3;
const int ALF = (1 << 20) - 3;
const int N = 1e5 + 13;
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

int f[N], inv[N];

int C(int n, int k) {
    return mul(f[n], mul(inv[k], inv[n - k]));
}

vector<int> dv[N], cnt[N];
vector<int> p[N];
bool isp[N];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            dv[j].push_back(i);
            cnt[j].push_back(j / i - 1);
        }

        if(isp[i]) {
            for(int j = i; j < N; j += i) {
                isp[j] = false;
                p[j].push_back(i);
            }
            isp[i] = true;
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = dv[i].size() - 1; j >= 0; j--) {
            for(int k = j + 1; k < dv[i].size(); k++)
                if(dv[i][k] % dv[i][j] == 0)
                    cnt[i][j] -= cnt[i][k];
        }
    }

//    for(int i = 1; i < N; i++) {
//        for(int j = dv.size() - 1; j >= 0; j--) {
//            for(int x : p[i]) if(i % (x * 1ll * j) == 0) {
//                cnt[]
//            }
//        }
//    }

    int n;
    cin >> n;

    int ans = 0;
    for(int c = 1; c <= n - 2; c++) {
        int x = n - c;
        for(int i = 0; i < dv[x].size(); i++) {
//            cout << c << ' ' << i << ' ' << dv[x][i] << ' ' << cnt[x][i] << endl;
            ans = sum(ans, mul(c * 1ll * dv[x][i] / __gcd(c, dv[x][i]), cnt[x][i]));
        }
//        for(int d : dv[x]) {
//            cout << c << ' ' << d << ' ' << c * 1ll * d / __gcd(c, d) << ' ' << x / d << endl;
////            ans = sum(ans, mul(c * 1ll * d / __gcd(c, d), x / d - 1));
//            ans = sum(ans, mul(c * 1ll * d / __gcd(c, d), x / d - 1));
//        }
    }

    cout << ans << endl;

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}