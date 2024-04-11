#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int a[100000], b[100000];

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    int ret = 0, probPrevSame = 1, M = modInverse(m), twoM = modInverse(2 * m);
    for (int i=0; i<n; i++) {
        if (a[i] && b[i] && a[i] != b[i]) {
            if (a[i] > b[i])
                add(ret, probPrevSame);
            break;
        }

        if (a[i] == 0 && b[i] == 0) {
            add(ret, mul(probPrevSame, mul(m - 1, twoM)));
            probPrevSame = mul(probPrevSame, M);
        } else if (a[i] == 0) {
            add(ret, mul(probPrevSame, mul(m - b[i], M)));
            probPrevSame = mul(probPrevSame, M);
        } else if (b[i] == 0) {
            add(ret, mul(probPrevSame, mul(a[i] - 1, M)));
            probPrevSame = mul(probPrevSame, M);
        }
    }

    cout << ret << "\n";

    return 0;
}