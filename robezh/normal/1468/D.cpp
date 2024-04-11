#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if(a > b) {
            b = n + 1 - b;
            a = n + 1 - a;
        }
        int tk = b - a - 1;
        vi crs;
        rep(i, 0, m) {
            int x; cin >> x; crs.push_back(x);
        }
        sort(all(crs), greater<>());
        int res = 0;
        for(int t = a; t < a + tk; t++) {
            if(crs.empty()) break;
            t = max(t, crs.back());
            if(t >= a + tk) break;
            
            crs.pop_back();
            res++;
        }
        cout << res << '\n';
    }

}