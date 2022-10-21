#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int mod = (int)1e9 + 7, N = (int)2e5 + 50;

int n, b[N];
map<ll, ll> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        mp.clear();
        cin >> n;
        rep(i, 0, n) cin >> b[i];
        mp[0] = 1;
        ll off = 0, sum = 1;
        rep(i, 0, n) {
            ll add = (sum - mp[off]) % mod;
            if(add < 0) add += mod;
            off -= b[i];
            mp[off + b[i]] = (mp[off + b[i]] + add) % mod;
            sum = (sum + add) % mod;
        }
        cout << sum << '\n';
    }
}