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
const int N = 505;

int n;
int res[N][N], cnt[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> res[i][i], cnt[i][i] = res[i][i];
    int len = n;
    rep(rd, 0, n) {
        int c0 = -1;
        for(int i = 0; i < len; i++) if(cnt[i + rd][i] == 1) c0 = i;
//        cout << rd << ": " << c0 << endl;
        for(int i = 0; i < c0; i++) res[i + rd + 1][i] = res[i + rd][i], cnt[i + rd + 1][i] = cnt[i + rd][i] - 1;
        for(int i = c0 + 1; i < len; i++) res[i + rd][i - 1] = res[i + rd][i], cnt[i + rd][i - 1] = cnt[i + rd][i] - 1;
        len--;
    }
    rep(i, 0, n) {
        rep(j, 0, i + 1) cout << res[i][j] << " ";
        cout << "\n";
    }
//    } rep(i, 0, n) {
//        rep(j, 0, i + 1) cout << cnt[i][j] << " ";
//        cout << "\n";
//    }



}