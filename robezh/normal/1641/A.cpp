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
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> x;
        rep(i, 0, n) cin >> a[i];
        sort(a, a + n);
        int res = 0;
        map<ll, int> mp;
        rep(i, 0, n) {
            if(a[i] % x == 0 && mp[a[i] / x] > 0) {
                mp[a[i] / x]--;
            } else {
                mp[a[i]]++;
            }
        }
        for(auto &e : mp) {
            res += e.second;
        }
        cout << res << '\n';
    }
}