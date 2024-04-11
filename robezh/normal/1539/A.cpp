#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        ll n, x, t;
        cin >> n >> t >> x;
        if(x / t + 1 >= n) {
            cout << n * (n - 1) / 2 << '\n';
        } else {
            cout << (x / t) * (x / t + 1) / 2 + (x / t) * (n - x / t - 1) << '\n';
        };

    }
}