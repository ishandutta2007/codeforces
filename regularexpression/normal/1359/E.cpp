#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

#define len(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int N = 5e5 + 7, M = 998244353;

int binpow(int val, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * val % M;
            n--;
        } else {
            val = val * val % M;
            n /= 2;
        }
    }
    return res;
}

int inv(int val) {
    return binpow(val, M - 2);
}

int fact[N];

int C(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv(fact[k]) % M * inv(fact[n - k]) % M;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % M;
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int a = 1; a <= n; a++) {
        int cnt = n / a;
        ans += C(cnt - 1, k - 1);
        if (ans >= M) ans -= M;
    }
    cout << ans;
    return 0;
}