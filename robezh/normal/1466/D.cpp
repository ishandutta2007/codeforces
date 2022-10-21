#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, deg[N], w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        ll res = 0;
        rep(i, 0, n) cin >> w[i], res += w[i];
        fill(deg, deg + n, 0);
        rep(i, 0, n - 1) {
            int a, b; cin >> a >> b; a--, b--;
            deg[a]++, deg[b]++;
        }
        vi xs;
        rep(i, 0, n) {
            while(deg[i] > 1) xs.push_back(w[i]), deg[i]--;
        }
        sort(all(xs), greater<>());
        for(int i = 0; i < n - 1; i++) {
            cout << res << " ";
            if(i < n - 2) res += xs[i];
        }
        cout << '\n';

    }

}