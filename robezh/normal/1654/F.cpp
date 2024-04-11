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
typedef pair<string, int> psi;
typedef pair<psi, vector<pii>> pxi;
typedef vector<int> vi;

const int N = 18;

int n;
string str;

string getxor(string s, int x) {
    string rs;
    rs.resize(sz(s));
    rep(i, 0, sz(s)) rs[i] = s[i ^ x];
    return rs;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> str;
    vi ord(1 << n);
    rep(i, 0, 1 << n) ord[i] = str[i] - 'a';

    for (int k = 1; k <= n; k++) {
        vector<pii> v(1 << n);
        rep(i, 0, 1 << n) v[i] = {ord[i], ord[i ^ (1 << (k - 1))]};
        vi idx(1 << n);
        iota(all(idx), 0);
        sort(all(idx), [&](const int i, const int j) {
            return v[i] < v[j];
        });
        int rk = 0, r = 0;
        for (int i = 0; i < (1 << n); i = r) {
            while(r < (1 << n) && v[idx[r]] == v[idx[i]]) {
                ord[idx[r++]] = rk;
            }
            rk++;
        }
    }
    int pos = 0;
    while(ord[pos]) pos++;
    cout << getxor(str, pos) << '\n';


}