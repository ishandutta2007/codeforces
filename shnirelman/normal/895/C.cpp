#include <bits/stdc++.h>

using namespace std;
using li = long long;
using ld = long double;

const int K = 71;
const int M = 1e9 + 7;

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);

    if(k & 1)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

int sum(int a, int b) {
    int res = a + b;
    while(res >= M)
        res -= M;
    while(res < 0)
        res += M;

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(K, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    vector<int> p, is(K, -1);
    for(int i = 2; i < K; i++) {
        if(is[i] == -1) {
            is[i] = i;
            p.push_back(i);
            for(int j = i * i; j < K; j += i)
                is[j] = i;
        }
    }
//cout << "ff" << endl;
    vector<int> f(n + 5, 1), r(n + 5, 1);
    for(int i = 1; i < f.size(); i++) {
        f[i] = f[i - 1] * 1ll * i % M;
        r[i] = pow2(f[i], M - 2);
    }
//cout << "ff" << endl;
    int k = p.size();
//    cout << k << endl;

    vector<vector<int>> dp(K, vector<int>(1 << k, 0));
    dp[0][0] = 1;
    for(int i = 1; i < K; i++) {
        //dp[i] = dp[i - 1];
//        cout << i << endl;
        if(a[i] == 0) {
            dp[i] = dp[i - 1];
            continue;
        }

        int ms = 0;
        int x = i;
        for(int j = 0; j < p.size(); j++) {
            if(x > 0 && x % p[j] == 0) {
                int cnt = 0;
                while(x % p[j] == 0) {
                    cnt++;
                    x /= p[j];
                }
                if(cnt % 2 == 1)
                    ms |= (1 << j);
            }
        }

//        cout << ms << endl;

        int odd = 0, even = 0;
        for(int j = 0; j <= a[i]; j += 2) {
            even = sum(even, f[a[i]] * 1ll * r[j] % M * 1ll * r[a[i] - j] % M);
        }

        for(int j = 1; j <= a[i]; j += 2) {
            odd = sum(odd, f[a[i]] * 1ll * r[j] % M * 1ll * r[a[i] - j] % M);
        }

//        cout << odd << ' ' << even << endl;

        for(int mask = 0; mask < dp[i].size(); mask++) {
            dp[i][mask] = sum(dp[i][mask], dp[i - 1][mask] * 1ll * even % M);
            dp[i][mask ^ ms] = sum(dp[i][mask ^ ms], dp[i - 1][mask] * 1ll * odd % M);
        }
    }

    cout << dp.back()[0] - 1 << endl;
}