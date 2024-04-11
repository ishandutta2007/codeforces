#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

void add(int &a, int b) {
    a = (a + b) % MOD;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int modInverse(long long a, int m = MOD) {
    int ret = 1, b = m - 2;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ret;
}

int cnt[1000001] = {}, prob[1000001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int N = modInverse(n);
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        int K = modInverse(k);
        for (int j=0; j<k; j++) {
            int a;
            cin >> a;
            cnt[a]++;
            add(prob[a], mul(N, K));
        }
    }

    int ret = 0;
    for (int i=1; i<=1000000; i++)
        add(ret, mul(prob[i], mul(cnt[i], N)));

    cout << ret << "\n";

    return 0;
}