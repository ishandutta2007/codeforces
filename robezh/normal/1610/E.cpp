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

int n, a[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        int r = 0;
        int res = 0;
        for (int i = 0; i < n; i = r) {
            while(r < n && a[r] == a[i]) r++;
            int cur = r - i;
            int x = r;
            while(x != n) {
                cur++;
                x = lower_bound(a, a + n, a[x] * 2 - a[i]) - a;
            }
            res = max(res, cur);
        }
        cout << n - res << '\n';

    }


}