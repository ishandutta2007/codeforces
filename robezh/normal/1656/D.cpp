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

ll solve(ll x) {
    x *= 2;
    ll l = 1, r = x;
    while(r % 2 == 0) r /= 2, l *= 2;
    if(l >= 2 && r - l - 1 >= 0) return l;
    if(r >= 2 && l - r - 1 >= 0) return r;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        cout << solve(n) << "\n";
    }


}