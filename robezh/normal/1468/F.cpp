#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n, a0, b0, a1, b1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
//    int x, y;
//    while(cin >> x >> y) {
//        cout << __gcd(x, y) << endl;
//    }
    cin >> T;
    while(T--) {
        cin >> n;
        map<pii, int> S;
        rep(i, 0, n) {
            cin >> a0 >> b0 >> a1 >> b1;
            int a = a1 - a0, b = b1 - b0;
            int g = abs(__gcd(a, b));
            a /= g, b /= g;
            S[{a, b}]++;
        }
        ll res = 0;
        for(auto &ps : S) {
            auto p = ps.first;
            res += 1LL * S[{-p.first, -p.second}] * ps.second;
        }
        cout << res / 2 << '\n';

    }
}