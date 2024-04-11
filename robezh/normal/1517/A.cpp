#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
//        cout << T << endl;
        cin >> n;
        if(n % 2050 == 0) {
            n /= 2050;
            ll res = 0;
            while(n) res += n % 10, n /= 10;
            cout << res << '\n';
        } else cout << -1 << '\n';
    }

}