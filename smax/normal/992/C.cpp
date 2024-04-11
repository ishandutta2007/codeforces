#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int modpow(long long a, long long b) {
    int ret = 1;
    while (b > 0) {
        if (b % 2 == 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ret;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
}

int mul(long long a, long long b) {
    return a * b % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long x, k;
    cin >> x >> k;

    if (x == 0) {
        cout << "0\n";
        return 0;
    }

    int ret = mul(modpow(2, k + 1), x % MOD);
    sub(ret, modpow(2, k));
    cout << (ret + 1) % MOD << "\n";

    return 0;
}