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
const int N = 10005;

int query(int x) {
    cout << "? " << x << endl;
    fflush(stdout);
    int y;
    cin >> y;
    return y;
}

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        vi res(n + 1, -1);
        rep(i, 1, n + 1) {
            if(res[i] != -1) continue;
            int y = query(i);
            vi cyc;
            int x = y;
            do {
                cyc.push_back(x);
                x = query(i);
            } while(x != y);
            rep(j, 0, sz(cyc)) {
                res[cyc[j]] = cyc[(j + 1) % sz(cyc)];
            }
        }
        cout << "! ";
        rep(i, 1, n + 1) cout << res[i] << " ";
        cout << endl;
        fflush(stdout);
    }

}