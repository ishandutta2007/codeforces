#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e6 + 50, INF = (int)1e9;

int n, m;
int a[N], b[N], c[N], d[N];
int mx[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 0, m) cin >> c[i] >> d[i];
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(a[i] <= c[j] && b[i] <= d[j]) {
                mx[c[j] - a[i]] = max(mx[c[j] - a[i]], d[j] - b[i] + 1);
            }
        }
    }
    int res = INF;
    int curmx = 0;
    for(int i = N - 1; i >= 0; i--) {
        curmx = max(curmx, mx[i]);
        res = min(res, curmx + i);
    }
    cout << res << '\n';

}