//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const li INF = 1e18 + 13;
const int N = 53;
const int M = 998244353;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 1e5;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int n, m;
int l[N], r[N];
int lx[N], rx[N];

int d[K];

int get(int x) {
    int mx = m / x;

    if(mx < n)
        return 0;

    for(int i = 0; i < n; i++) {
        lx[i] = (l[i] + x - 1) / x;
        rx[i] = (r[i]) / x;

        if(rx[i] < lx[i])
            return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(mx + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        vector<int> s(mx + 2, 0);
        for(int j = 1; j < s.size(); j++)
            s[j] = sum(s[j - 1], dp[i][j - 1]);

        for(int j = lx[i]; j <= mx; j++) {
            int lf = max(0, j - rx[i]);
            int rg = j - lx[i];
            dp[i + 1][j] = dif(s[rg + 1], s[lf]);
        }
    }

    int res = 0;
    for(int i = 0; i < mx + 1; i++)
        res = sum(res, dp[n][i]);

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    for(int i = 2; i < K; i++) {
        if(d[i] == 0) {
            d[i] = i;

            if(i * 1ll * i < K)
                for(int j = i * i; j < K; j += i)
                    d[j] = i;
        }
    }

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    int res = 0;
    for(int i = 1; i <= m; i++) {
        int cur = 1;
        int x = i;
        while(x > 1) {
            int dv = d[x];
            x /= dv;
            if(x % dv == 0)
                cur = 0;
            cur *= -1;
        }

        if(cur != 0)
            res = sum(res, (get(i) * cur + M) % M);
    }

    cout << res << endl;
}