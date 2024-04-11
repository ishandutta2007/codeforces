#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)3e5 + 50;

int n, a[N];

bool solve() {
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    int up = a[0], dn = 0;
    rep(i, 1, n) {
        int nxtup = min(a[i] - dn, up);
        int nxtdn = a[i] - nxtup;
        if(nxtdn < 0 || nxtup < 0) return false;
        dn = nxtdn;
        up = nxtup;
//        cout << nxtup << " " << nxtdn << endl;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}