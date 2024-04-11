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

const int N = (int)1e5 + 50;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n; cin >> n;
        vi vs[2];
        rep(i, 0, n) {
            int x; cin >> x;
            vs[i % 2].push_back(x);
        }
        rep(i, 0, 2) sort(all(vs[i]));
        vi res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            res[i] = vs[i % 2].back();
            vs[i % 2].pop_back();
        }
        cout << (is_sorted(all(res)) ? "YES" : "NO") << "\n";
    }

}