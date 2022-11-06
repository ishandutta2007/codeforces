#include<bits/stdc++.h>
using namespace std;

#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

const int M = 998244353;

int pw(int x, int n) {
    int y = 1;
    x %= M;
    while (n > 0) {
        if (n & 1) {
            y = (y * x) % M;
            n--;
        } else {
            x = (x * x) % M;
            n /= 2;
        }
    }
    return y;
}

int inv(int x) {
    return pw(x, M - 2);
}

const int N = 1e6 + 7;

int prob[N], c[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            prob[x] += inv(k);
            prob[x] %= M;
            c[x]++;
        }
    }
    for (int i = 0; i < N; i++) {
        prob[i] *= inv(n);
        prob[i] %= M;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int p2 = c[i] * inv(n) % M;
        ans += p2 * prob[i] % M;
        ans %= M;
    }
    cout << ans;
    return 0;
}