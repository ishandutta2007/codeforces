//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e8 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const ld eps = 1e-6;
const int B = 400;
const int K = 400;
const int LOGN = 20;

/*
*/

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
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

int cnt[N * 2];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];

    }

    int ans = n - 1;

    for(int d = -B; d < B; d++) {
        int mx = 0;
        for(int i = 0; i < n; i++) {
//            cnt[a[i] - i * d]++;
            mx = max(mx, ++cnt[a[i] - i * d + N]);
        }

        ans = min(ans, n - mx);

        for(int i = 0; i < n; i++)
            cnt[a[i] - i * d + N]--;
    }
//cout << ans << endl;
//return 0;
    for(int i = 0; i < n; i++) {
        int mx = 0;
//        cout << i << endl;
        for(int j = 1; j < B && i + j < n; j++) {
//            cout << i << ' ' << j << endl;
            if((a[i + j] - a[i]) % j == 0) {
                mx = max(mx, ++cnt[(a[i + j] - a[i]) / j + N]);
            }
        }

        ans = min(ans, n - 1 - mx);

        for(int j = 1; j < B && i + j < n; j++) {
            if((a[i + j] - a[i]) % j == 0) {
                --cnt[(a[i + j] - a[i]) / j + N];
            }
        }
    }

    cout << ans << endl;
}