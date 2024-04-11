#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 1;
const int A = 26;


/*


*/

int sum(int a, int b) {
    int res = a + b;

    if(res >= M)
        res -= M;

    return res;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);

    if(k & 1)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

int p[N], r[N], pw10[N];

int C(int n, int k) {
    return (k > n ? 0 : p[n] * 1ll * r[k] % M * 1ll * r[n - k] % M);
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    p[0] = 1;
    r[0] = 1;
    for(int i = 1; i < N; i++) {
        p[i] = p[i - 1] * 1ll * i % M;
        r[i] = pow2(p[i], M - 2);
    }

    pw10[0] = 1;
    for(int i = 1; i < N; i++) {
        pw10[i] = pw10[i - 1] * 10ll % M;
    }

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cur = 0;
    int res = 0;
    for(int i = n - 1; i >= 0; i--) {
        int x = (s[i] - '0');
        int len = n - i;
        res = sum(res, pw10[len - 1] * 1ll * C(n - len, k) % M * 1ll * x % M);

//        cout << i << ' ' << res << endl;

        if(len > 1) {
            cur = sum(cur, pw10[len - 2] * 1ll * C(n - len, k - 1) % M);
            res = sum(res, cur * 1ll * x % M);
        }
//        cout << i << ' ' << res << ' ' << cur << endl;
    }

    cout << res;
}