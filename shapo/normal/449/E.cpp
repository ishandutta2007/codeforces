#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

const int MAXN = 1000001;
const int MD = 1000000007;

int lp[MAXN];
vector< int > pr;
int phi[MAXN], pil[MAXN];
int sum[MAXN][3];

int
getPhi(int x)
{
    int res = x;
    while (x != 1) {
        int div = lp[x];
        res /= div;
        res *= (div - 1);
        while (x % div == 0) {
            x /= div;
        }
    }
    return res;
}



void
getPil(int x, int mult, int div_m, int &res)
{
    if (x == 1) {
        res = (res + mult * phi[div_m]) % MD;
    } else {
        int div = lp[x];
        int cnt = 0;
        while (x % div == 0) {
            x /= div;
            ++cnt;
        }
        for (int j = 0; j <= cnt; ++j, mult *= div, div_m /= div) {
            getPil(x, mult, div_m, res);
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i <= 1000000; ++i) {
        lp[i] = 0;
    }
    for (int i = 2; i <= 1000000; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < int(pr.size()) && pr[j] <= lp[i] && 1000000 / i >= pr[j]; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    for (int i = 1; i <= 1000000; ++i) {
        phi[i] = getPhi(i);
        pil[i] = (MD - 2 * i + 1);
        getPil(i, 1, i, pil[i]);
    }
    sum[1][0] = sum[1][1] = sum[1][2] = 1;
    for (int i = 2, tmp = 0, add_sum = 0; i <= 1000000; ++i) {
        int add = (1ll * i * i + (tmp + pil[i]) * 2) % MD;
        sum[i][0] = (sum[i - 1][0] + add) % MD;
        add = 1ll * add * i % MD;
        sum[i][1] = (sum[i - 1][1] + add) % MD;
        add = 1ll * add * i % MD;
        sum[i][2] = (sum[i - 1][2] + add) % MD;
        add_sum = (add_sum + 2 * (i - 1) - 1) % MD;
        tmp = (tmp + add_sum) % MD;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;
        if (n > m) {
            swap(n, m);
        }
        int res = sum[n][2];
        res = (res + 1ll * (n + 1) * (m + 1) % MD * sum[n][0] 
                - 1ll * (n + m + 2) * sum[n][1] % MD + MD) % MD;
        cout << res << '\n';
    }
    return 0;
}