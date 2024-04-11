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

ll ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    ll x; cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n; cin >> n;
        ll tot = ask(1, n);
        int l = 0, r = n, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(ask(1, mid) == tot) r = mid;
            else l = mid;
        }
        int m2 = r;
        int len2 = ask(1, m2) - ask(1, m2 - 1) + 1;
        int m1 = m2 - len2 + 1;
        int len3 = ask(1, m1 - 1) - ask(1, m1 - 2) + 1;
        int m0 = m1 - len3;
        cout << "! " << m0 << " " << m1 << " " << m2 << endl;
        fflush(stdout);
    }
}