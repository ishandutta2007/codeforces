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
typedef pair<int, pii> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50;

int n;


bool good(vi xs) {
    rep(i, 0, sz(xs)) {
        if(xs[i] != xs[sz(xs) - 1 - i]) return false;
    }
    return true;
}

vi create(vi &xs, int x) {
    vi res;
    rep(i, 0, sz(xs)) {
        if(xs[i] != x) res.push_back(xs[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        vi a(n, 0);
        rep(i, 0, n) cin >> a[i];
        if(good(a)) {
            cout << "YES\n";
        } else {
            int l = 0, r = n - 1;
            while(a[l] == a[r]) l++, r--;
            cout << (good(create(a, a[l])) || good(create(a, a[r])) ? "YES" : "NO") << '\n';
        }
    }

}