#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int INF = (int)1e9;

int check(int a, int b, int k) {
    b += k;
    int res = k;
    while(a) a /= b, res++;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;
    while(T--) {
        int a, b; cin >> a >> b;
        int res = INF;
        rep(k, (b == 1 ? 1 : 0), 35) {
            res = min(res, check(a, b, k));
        }
        cout << res << '\n';
    }

}