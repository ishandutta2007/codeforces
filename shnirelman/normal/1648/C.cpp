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
const int N = 2e5 + 13;
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

int p[N], inv[N];

int t[N];

void add(int i, int x) {
    for(; i < N; i |= (i + 1))
        t[i] = sum(t[i], x);
}

int get(int i) {
    int res = 0;

    for(; i >= 0; i = (i & (i + 1)) - 1)
        res = sum(res, t[i]);

    return res;
}

int a[N], b[N];
int ca[N], cb[N];
int ca1[N];

/*
3 2
1 1 2
1 2

2 1
1 2
2
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ca[a[i]]++;
    }

    for(int j = 0; j < m; j++) {
        cin >> b[j];
        cb[b[j]]++;
    }

    int ans = 0;
    if(n < m) {
        bool res = true;
        for(int i = 0; i < N; i++)
            ca1[i] = ca[i];

        for(int i = 0; i < n; i++) {
            if(ca1[b[i]] <= 0) {
                res = false;
                break;
            }

            ca1[b[i]]--;
        }

        ans = res;
    }

    p[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], i);
        inv[i] = pow2(p[i], M - 2);
    }

    int res = 1;
    for(int i = 1; i < N; i++) {
        res = mul(res, inv[ca[i]]);
    }

    for(int i = 1; i < N; i++) if(ca[i]) {
        add(i, mul(mul(res, p[n - 1]), mul(p[ca[i]], inv[ca[i] - 1])));
    }

    int factor = 1;

//    for(int j = 1; j < 4; j++) {
//            cout << "BIT " << j << ' ' << dif(get(j), get(j - 1)) << ' ' << mul(dif(get(j), get(j - 1)), factor) << endl;
//        }

    for(int i = 0; i < min(n, m); i++) {
        ans = sum(ans, mul(factor, get(b[i] - 1)));
//        cout << i << ' ' << ans << ' '<< factor << endl;

        if(ca[b[i]] == 0 || i == min(n, m) - 1)
            break;

        factor = mul(factor, mul(inv[n - i - 1], p[n - i - 2]));
        factor = mul(factor, mul(p[ca[b[i]]], inv[ca[b[i]] - 1]));
        res = mul(res, mul(p[ca[b[i]]], inv[ca[b[i]] - 1]));

        ca[b[i]]--;

        int x = dif(get(b[i]), get(b[i] - 1));
        if(x > 0)
            add(b[i], M - x);

//        cout << "res " << res << endl;
//for(int j = 1; j < 4; j++) {
//            cout << "BIT " << j << ' ' << dif(get(j), get(j - 1)) << ' ' << mul(dif(get(j), get(j - 1)), factor) << endl;
//        }
        if(ca[b[i]]) {
//            cout << "modify " << mul(res, p[n - i - 2]) << ' ' << mul(mul(res, p[n - i - 2]), mul(p[ca[b[i]]], inv[ca[b[i] - 1]])) << endl;
//            cout << "modify " << mul(p[ca[b[i]]], inv[ca[b[i]] - 1]) << ' ' << ca[b[i]] << ' ' << p[ca[b[i]]] << endl;
            add(b[i], mul(mul(mul(res, p[n - i - 2]), mul(p[ca[b[i]]], inv[ca[b[i]] - 1])), pow2(factor, M - 2)));
        }

//        for(int j = 1; j < 4; j++) {
//            cout << "BIT " << j << ' ' << dif(get(j), get(j - 1)) << ' ' << mul(dif(get(j), get(j - 1)), factor) << endl;
//        }
    }

    cout << ans << endl;
}