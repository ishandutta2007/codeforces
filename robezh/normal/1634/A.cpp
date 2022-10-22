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
const int N = (int)3e5 + 50;



int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        string rs = s;
        reverse(all(rs));
        cout << (k == 0 || rs == s ? 1 : 2) << '\n';
    }
}