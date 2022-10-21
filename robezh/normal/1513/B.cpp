#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50, mod = (int)1e9 + 7;

int n, a[N], good[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        bool bad = false;
        fill(good, good + n, true);
        rep(b, 0, 30) {
            int cnt = 0;
            rep(i, 0, n) cnt += (a[i] >> b & 1);
            if(cnt == n - 1) {
                bad = true;
                break;
            }
            if(cnt <= n - 2) {
                rep(i, 0, n) if((a[i] >> b & 1)) good[i] = false;
            }
        }
        int cntgood = 0;
        rep(i, 0, n) cntgood += good[i];
//        cout << cntgood << endl;
        if(bad || cntgood < 2) {
            cout << 0 << '\n';
            continue;
        }
        ll res = 1LL * cntgood * (cntgood - 1) % mod;
        for(int i = n - 2; i >= 1; i--) res *= i, res %= mod;
        cout << res << '\n';

    }

}