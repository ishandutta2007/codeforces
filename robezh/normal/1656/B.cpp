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

int n, k;
int a[N];

void solve() {
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    map<int, int> mp;
    rep(i, 0, n) {
        if(mp.count(a[i] + k) || mp.count(a[i] - k)) return cout << "YES\n", void();
        mp[a[i]]++;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}