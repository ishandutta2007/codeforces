
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int mod = (int)1e9 + 7;

ll fp(ll x, int k) {
    if(k == 0) return 1;
    ll hf = fp(x, k / 2);
    return k % 2 == 0 ? hf * hf % mod : hf * hf % mod * x % mod;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    cout << fp(((fp(2, m) - 1 + mod) % mod), n) << '\n';

}