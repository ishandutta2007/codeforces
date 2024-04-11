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

int n, q;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    cin >> str;
    int res = 0;
    rep(i, 0, n - 2) {
        if(str.substr(i, 3) == "abc") res++;
    }
    while(q--) {
        int i; char c;
        cin >> i >> c; i--;
        rep(j, max(0, i - 2), min(i, n - 3) + 1) {
            res -= str.substr(j, 3) == "abc";
        }
        str[i] = c;
        rep(j, max(0, i - 2), min(i, n - 3) + 1) {
            res += str.substr(j, 3) == "abc";
        }
        cout << res << '\n';
    }



}