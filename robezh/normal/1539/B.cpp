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

const int N = (int)1e5 + 50;

int n, q;
int psum[N][26];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    cin >> str;
    str = " " + str;
    rep(i, 1, n + 1) {
        rep(b, 0, 26) psum[i][b] = psum[i - 1][b];
        psum[i][str[i] - 'a']++;
    }
    while(q--) {
        int l, r; cin >> l >> r;
        ll res = 0;
        rep(b, 0, 26) res += (psum[r][b] - psum[l - 1][b]) * (b + 1);
        cout << res << '\n';
    }


}