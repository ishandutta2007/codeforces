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


void solve(vi &vis, int a, int b, int x, int y) {
    rep(s1, 0, min(a, x) + 1) {
        int s2 = x - s1;
        int e1 = a - s1;
        int e2 = y - e1;
        if(e2 >= 0 && e2 <= y && s1 + e2 <= a + b) vis[s1 + e2] = 1;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int a, b; cin >> a >> b;
        int tm = a + b;
        vi vis = vi(a + b + 1, 0);
        if(tm % 2 == 0) {
            solve(vis, a, b, tm / 2, tm / 2);
        } else {
            solve(vis, a, b, tm / 2, tm / 2 + 1);
            solve(vis, a, b, tm / 2 + 1, tm / 2);
        }
        int cnt = 0;
        rep(i, 0, a + b + 1) cnt += vis[i];
        cout << cnt << '\n';
        rep(i, 0, a + b + 1) if(vis[i]) cout << i << " ";
        cout << '\n';
    }


}