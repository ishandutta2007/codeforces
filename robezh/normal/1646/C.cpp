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

int calc(ll x, ll f, int c) {
    int res = __builtin_popcountll(x);
    if(f > x) return res;
    res = min(res, calc(x - f, f * (c + 1), c + 1) + 1);
    res = min(res, calc(x, f * (c + 1), c + 1));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        cout << calc(n, 1, 1) << '\n';
    }

}