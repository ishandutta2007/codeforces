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

const int N = (int)2e5 + 50;

int n, x;
int a[N];
ll psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> x;
        rep(i, 1, n + 1) cin >> a[i];
        sort(a + 1, a + n + 1);
        rep(i, 1, n + 1) psum[i] = psum[i - 1] + a[i];
        int p = n;
        while(psum[p] > x) p--;
        ll res = 0;
        rep(i, 1, p + 1) {
            ll d = (x - psum[i]) / i + 1;
            res += d;
        }
        cout << res << '\n';
    }


}