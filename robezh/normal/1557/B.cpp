#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e5 + 50;

int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        vi vs;
        rep(i, 0, n) cin >> a[i], vs.push_back(a[i]);
        sort(all(vs));
        rep(i, 0, n) a[i] = lower_bound(all(vs), a[i]) - vs.begin();
        int c = 0;
        rep(i, 0, n - 1) c += (a[i] + 1 != a[i + 1]);
        cout << (c + 1 <= k ? "YES" : "NO") << '\n';
    }

}