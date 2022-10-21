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

const int N = (int)105;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        map<int, int> mp;
        rep(i, 0, n) {
            int a; cin >> a;
            mp[abs(a)]++;
        }
        int res = 0;
        for(auto p : mp ) {
            if(p.first != 0) res += min(p.second, 2);
            else res += min(p.second, 1);
        }
        cout << res << '\n';
    }


}