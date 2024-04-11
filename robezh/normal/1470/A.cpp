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

const int N = (int)3e5 + 50;

int n, m;
int k[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> k[i];
        rep(i, 1, m + 1) cin >> c[i];
        sort(k, k + n);
        reverse(k, k + n);
        int pt = 1;
        ll res = 0;
        rep(i, 0, n) {
            if(pt < k[i]) res += c[pt++];
            else res += c[k[i]];
        }
        cout << res << '\n';
    }
}