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

int inv(int n) {
    return pow2(n, M - 2);
}

vector<int> w[LOGN];
vector<int> rv[LOGN];

void precalc() {
    for(int i = 0; i < LOGN; i++) {
        w[i].resize(1 << i, 1);
        int x = pow2(g, (M - 1) >> i + 1);
        for(int j = 1; j < (1 << i); j++) {
            w[i][j] = mul(w[i][j - 1], x);
        }
    }

    rv[0].resize(1, 0);
    for(int i = 1; i < LOGN; i++) {
        rv[i].resize(1 << i);
//        cout << "rv " << i << ' ' << rv[i].size() << endl;
        for(int j = 0; j < (1 << i); j++) {
            rv[i][j] = ((rv[i - 1][j & ((1 << i - 1) - 1)] << 1) | (j >= (1 << i - 1)));
        }
    }
}

void fft(int a[N], int n, int ln, bool inv) {
//    cout << "fft " << endl;
    for(int i = 0; i < n; i++) {
//        cout << ln << ' ' << i << ' ' << rv[ln].size() << endl;
        int j = rv[ln][i];
//        cout << i << ' ' << j << endl;
        if(i < j)
            swap(a[i], a[j]);
    }

//    cout << "fft 2" << endl;

    for(int i = 0; (1 << i) < n; i++) {
        int len = (1 << i);
        for(int k = 0; k < n; k += (len << 1)) {
            for(int pos = k; pos < k + len; pos++) {
                int l = a[pos];
                int r = mul(a[pos + len], w[i][pos - k]);

                a[pos] = sum(l, r);
                a[pos + len] = dif(l, r);
            }
        }
    }

    if(inv) {
        int dv = pow2(n, M - 2);
        for(int i = 0; i < n; i++) {
            a[i] = mul(a[i], dv);
        }
        reverse(a + 1, a + n);
    }
}


int aa[N], bb[N], cc[N];

vector<int> multiply(vector<int> a, vector<int> b) {
    int n = 1, ln = 0;
    while(n < a.size() + b.size())
        n *= 2, ln++;
    for(int i = 0; i < n; i++)
        aa[i] = (i < a.size() ? a[i] : 0);
    for(int i = 0; i < n; i++)
        bb[i] = (i < b.size() ? b[i] : 0);

    fft(aa, n, ln, false);
    fft(bb, n, ln, false);

    for(int i = 0; i < n; i++)
        cc[i] = mul(aa[i], bb[i]);

    fft(cc, n, ln, true);

    vector<int> c(n);
    for(int i = 0; i < n; i++)
        c[i] = cc[i];
    while(!c.empty() && c.back() == 0)
        c.pop_back();
    return c;
}

vector<int> multiply2(vector<int> a) {
    int n = 1, ln = 0;
    while(n < a.size() * 2)
        n *= 2, ln++;
    for(int i = 0; i < n; i++)
        aa[i] = (i < a.size() ? a[i] : 0);

    fft(aa, n, ln, false);

    for(int i = 0; i < n; i++)
        cc[i] = mul(aa[i], aa[i]);

    fft(cc, n, ln, true);

    vector<int> c(n);
    for(int i = 0; i < n; i++)
        c[i] = cc[i];
    while(!c.empty() && c.back() == 0)
        c.pop_back();
    return c;
}

mt19937 rnd(0);

/*
*/

int dp[17][200103];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precalc();
//    {
//        vector<int> a = {1, 1};
//        vector<int> c = multiply2(a);
//        for(int x : c)
//            cout << x << ' ';
//        cout << endl;
//    }

    int n, k, f;
    cin >> n >> k >> f;

    for(int i = 0; i <= f; i++) {
        dp[1][i] = (i <= k);
    }

    for(int i = 2; i <= n; i++) {
        vector<int> a(f + 1);
        for(int j = 0; j <= f; j++)
            a[j] = dp[i - 1][j];

        int res = pow2(k + 1, (1 << i) - 2);
//        cout << "res = " << res << endl;

        vector<int> c = multiply2(a);
//        cout << "a : ";
//        for(int x : a)
//            cout << x << ' ';
//        cout << endl;
//
//        cout << "c : ";
//        for(int x : c)
//            cout << x << ' ';
//        cout << endl;

        int s = 0;
        for(int j = 0; j <= f; j++) {
//            int x = ;
            dp[i][j] = sum((j <= k ? dif(res, s) : 0), mul(c[j], max(0, k - j)));
            s = sum(s, c[j]);

//            assert(j <= k || dp[i][j] == 0);
        }
    }
//
//    for(int i = 1; i <= n; i++) {
//        cout << "i = " << i << " : ";
//        for(int j = 0; j <= f; j++)
////            if(i == 2)
////                cout << (dp[i][j] - 1444) << ' ';
////            else
//                cout << dp[i][j] << ' ';
//        cout << endl;
//    }

    int ans = 0;
    for(int x = 0; x <= f; x++)
        ans = sum(ans, mul(dp[n][x], dp[n][f - x]));
    cout << ans << endl;
}