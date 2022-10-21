#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        map<int, int> mp;
        cin >> n >> k;
        rep(i, 0, n) {
            int a; cin >> a;
            int rem = (k - a % k) % k;
            mp[rem]++;
        }
        ll res = -1;
        for(auto &p : mp) {
            if(p.first) res = max(res, 1LL * (p.second - 1) * k + p.first);
        }
        cout << res + 1 << '\n';
    }
}