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
const int N = (int)1e6 + 5;

int n, m;
bool bad[N];
int psum[N];
string str[N];
int q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) {
        cin >> str[i];
    }
    rep(i, 1, n) {
        rep(j, 1, m) {
//            if(str[i][j] == 'X') continue;
            bad[j] |= (str[i - 1][j] == 'X' && str[i][j - 1] == 'X');
        }
    }
    rep(i, 1, m) psum[i] = psum[i - 1] + bad[i];
    cin >> q;
    while(q--) {
        int l, r; cin >> l >> r; l--, r--;
        cout << (psum[r] - psum[l] == 0 ? "YES" : "NO") << '\n';
    }


}