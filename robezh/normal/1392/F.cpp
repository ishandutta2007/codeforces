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
const int N = (int)1e6 + 50;

int n;
ll sum = 0;
ll h[N];

mt19937 rng(30000);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        ll x; cin >> x; sum += x;
    }
    ll l = 0, r = (ll)1e12, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(1LL * (mid + mid + n - 1) * n / 2 <= sum) l = mid;
        else r = mid;
    }
    for(int i = 0; i < n; i++) h[i] = l + i, sum -= h[i];
    for(int i = 0; i < n; i++) {
        if(sum) sum--, h[i]++;
        cout << h[i] << " ";
    }
    cout << '\n';

}