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
const int N = (int)105;

int n, m,
a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        set<int> S;
        rep(i, 0, n) cin >> a[i], S.insert(a[i]);
        int need = sz(S) - 1;
        if(m == 1) {
            if(need == 0) cout << 1 << '\n';
            else cout << -1 << '\n';
        } else {
            cout << max(1, (need + (m - 1) - 1) / (m - 1)) << '\n';
        }
    }
}