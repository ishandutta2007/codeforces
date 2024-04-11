#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 152;
const int M = 5700;

int a[N], b[N];
int n, k, s, la, lb;
int d1[2][N][M];
int d2[2][N][M];
int sum;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k >> s;
    s = min(s, M - 1);

    la = k;
    lb = n - k;

    for (int i = 0; i < k; i++) {
        cin >> a[k - i - 1];
        sum += a[k - i - 1];
    }
    for (int i = k; i < n; i++)
        cin >> b[i - k];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            d2[0][i][j] = d2[1][i][j] = 1e9;

    for (int i = 0; i < M; i++) {
        d1[0][1][i] = a[0];
        d1[0][0][i] = 0;
        d2[0][1][i] = b[0];
        d2[0][0][i] = 0;
    }

    int q;

    for (int num = 1; num < la; num++) {
        q = num % 2;

        for (int kk = 0; kk <= num + 1; kk++)
            for (int ss = 0; ss <= s; ss++) {
                if (ss >= num && kk > 0)
                    d1[q][kk][ss] = max(d1[1-q][kk][ss], d1[1-q][kk - 1][ss - num] + a[num]);
                else
                    d1[q][kk][ss] = d1[1-q][kk][ss];
            }
    }

    for (int num = 1; num < lb; num++) {
        q = num % 2;

        for (int kk = 0; kk <= num + 1; kk++)
            for (int ss = 0; ss <= s; ss++) {
                if (ss >= num && kk > 0)
                    d2[q][kk][ss] = min(d2[1-q][kk][ss], d2[1-q][kk - 1][ss - num] + b[num]);
                else
                    d2[q][kk][ss] = d2[1-q][kk][ss];
            }
    }

    int na = (la - 1) % 2;
    int nb = (lb - 1) % 2;
    int sa, sb;

    int ans = 0;

    for (int kk = 1; kk <= min(la, lb); kk++) {
        for (int ss = 0; ss <= s; ss++) {
            sa = ss;
            sb = s - sa - kk;
            if (sb < 0)
                continue;
            ans = min(ans, d2[nb][kk][sb] - d1[na][kk][sa]);
        }
        ans = ans;
    }

    cout << ans + sum;

    return 0;
}