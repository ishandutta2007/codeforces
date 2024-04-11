#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<int, int> P;
const int N = (int)3e5 + 50;

int n, q, mod;
int cnt = 0;
int a[N], b[N], c[N];
int f[N];

void add(int i, int val) {
    if(i < 0 || i >= n) return ;
    cnt -= (c[i] == 0);
    (c[i] += val) %= mod;
    cnt += (c[i] == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q >> mod;
    rep(i, 0, n) cin >> a[i], c[i] = a[i];
    rep(i, 0, n) cin >> b[i], c[i] -= b[i], c[i] %= mod;
    f[1] = 1;
    rep(i, 2, n + 1) f[i] = (f[i - 1] + f[i - 2]) % mod;
    for (int i = n - 1; i >= 0; i--) {
        if(i >= 1) (c[i] -= c[i - 1]) %= mod;
        if(i >= 2) (c[i] -= c[i - 2]) %= mod;
        cnt += (c[i] == 0);
    }

    rep(i, 0, q) {
        char s; int l, r;
        cin >> s >> l >> r; l--, r--;
        int sig = (s == 'A' ? 1 : -1);
        add(l, sig);
        add(r + 1, -sig * f[r - l + 2]);
        add(r + 2, -sig * f[r - l + 1]);
        cout << (cnt == n ? "YES" : "NO") << '\n';
    }


}