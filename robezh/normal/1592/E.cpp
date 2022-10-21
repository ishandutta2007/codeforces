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

const int N = (int)1e6 + 5, B = 20;

int n, a[N];
int lf[B][2];
int psum[N];
map<int, int> mp[B][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    int res = 0;
    rep(b, 0, B) mp[b][0][0] = 0;
    rep(i, 1, n + 1) {
        psum[i] = psum[i - 1] ^ a[i];
        int c = i % 2;

        rep(b, 0, B) {
            if(i >= 2 && (a[i] >> b & 1) && (a[i - 1] >> b & 1)) {}
            else mp[b][c].clear();

            auto it = mp[b][c].find(psum[i] >> (b + 1));
            if(it != mp[b][c].end()) res = max(res, i - it -> second);
            else mp[b][c][psum[i] >> (b + 1)] = i;
        }
    }
    cout << res << '\n';
}