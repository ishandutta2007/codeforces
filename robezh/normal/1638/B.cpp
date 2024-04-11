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
typedef pair<int, int> P;

const int N = (int)1e5 + 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vi x(n);
        vi ps[2];
        rep(i, 0, n) cin >> x[i], ps[x[i] % 2].push_back(x[i]);
        cout << (is_sorted(all(ps[0])) && is_sorted(all(ps[1])) ? "YES" : "NO") << '\n';
    }

}