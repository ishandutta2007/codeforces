#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
const int N = (int)2e5 + 50;

int n, m;
vector<vi> a;

void solve() {
    cin >> m >> n;
    a = vector<vi>(n, vi(m, 0));
    rep(i, 0, m) rep(j, 0, n) cin >> a[j][i];
    auto b = a;
    sort(all(b));
//    reverse(all(b));
//    rep(i, 0, n) {
//        rep(j, 0, m) cout << b[i][j] << " ";
//        cout << endl;
//    }
    rep(i, 0, n - 1) {
        bool ok = true;
        rep(j, 0, m) ok &= b[i][j] <= b[i + 1][j];
        if(!ok) {
            cout << -1 << '\n';
            return ;
        }
    }
    vi df;
    rep(i, 0, n) {
        if(a[i] != b[i]) df.push_back(i);
    }
    if(sz(df) > 2) {
        cout << -1 << '\n';
    } else if(sz(df) == 2) {
        cout << df[0] + 1 << " " << df[1] + 1 << '\n';
    } else {
        cout << 1 << " " << 1 << '\n';
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}