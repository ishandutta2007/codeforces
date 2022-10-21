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
typedef pair<string, ll> psl;
#define lson(x) x * 2 + 1
#define rson(x) x * 2 + 2

const int mod = 998244353;
string str;
int n;

psl solve(int x, int l, int r) {
    if(l == r) {
        return {string() + str[x], 1};
    }
    int mid = (l + r) / 2;
    auto L = solve(lson(x), l, mid);
    auto R = solve(rson(x), mid + 1, r);
//    cout << x << " " << l << " " << r << ": " << L.first << ", " << R.first << endl;
    if(L.first == R.first) {
        return {str[x] + L.first + R.first, L.second * R.second % mod};
    } else {
        if(L.first > R.first) swap(L, R);
        return {str[x] + L.first + R.first, L.second * R.second * 2 % mod};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> str;
    auto p = solve(0, 0, (1 << (n - 1)) - 1);
    cout << p.second << '\n';

}