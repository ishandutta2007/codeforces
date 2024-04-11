#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int K = 8;
const int N = 3e5 + 13;
const int LOGN = 35;
const int M = 998244353;
const int INF = 1e9 + 13;

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

bool isp[N];

//void solve() {
//}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++)
        isp[i] = true;
    for(int i = 2; i < N; i++) {
        if(isp[i]) {
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    isp[j] = false;
        }
    }

    li n, m;
    cin >> n >> m;

    int ans = 0;
    int cur = 1;
    for(int i = 0; i < n; i++) {
        cur = mul(cur, m % M);
        ans = sum(ans, cur);
    }

//    cout << ans << endl;

    li lcm = 1;
    int res = m % M;
    for(int i = 1; i <= n; i++) {
        ans = dif(ans, res);
//        lcm = lcm * (i + 1) / __gcd(lcm, i + 1ll);
        if(isp[i + 1])
            lcm *= i + 1;
//        cout << i << ' ' << lcm << ' ' << res << ' ' << ans << endl;

        if(lcm > m) {
            res = 0;
            break;
        }

        res = mul(res, m / lcm % M);
    }

//    cout << dif(ans, res) << endl;
    cout << ans << endl;
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}