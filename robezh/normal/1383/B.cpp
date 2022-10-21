#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, a[N];
int dp[1000][1000][2];

int solve(int x, int y, int mode) {
    if(dp[x][y][mode] != -1) return dp[x][y][mode];
    if(mode) {
        dp[x][y][mode] = 0;
        if(x > 0) dp[x][y][mode] |= 1 - solve(x - 1, y, 1 - mode);
        if(y > 0) dp[x][y][mode] |= solve(x, y - 1, 1 - mode);
    } else {
        dp[x][y][mode] = (x == 0);
        if(x > 0) dp[x][y][mode] = min(dp[x][y][mode], 1 - solve(x - 1, y, 1 - mode));
        if(y > 0) dp[x][y][mode] = min(dp[x][y][mode], solve(x, y - 1, 1 - mode));
    }

    return dp[x][y][mode];
}

void solve() {
    cin >> n;
    int sum = 0;
    rep(i, 0, n) cin >> a[i], sum ^= a[i];
    if(sum == 0) {
        cout << "DRAW\n";
        return ;
    }
    int fir = 0;
    for(int i = 0; i < 30; i++) {
        if(sum >> i & 1) fir = i;
    }
//    cout << fir << endl;
    int cnt[2] = {0, 0};
    rep(i, 0, n) {
        cnt[a[i] >> fir & 1]++;
    }
//    cout << (solve(cnt[0], cnt[1], 1) ? "WIN\n" : "LOSE\n") << endl;
//    cout << cnt[0] << " " << cnt[1] << endl;
    if(cnt[1] % 4 == 1) {
        cout << "WIN\n";
    } else {
        cout << (((cnt[0] % 2 == 0) ^ (cnt[1] % 4 == 1)) ? "LOSE\n" : "WIN\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

//    memset(dp, -1, sizeof(dp));
//    for(int i = 0; i < 20; i++) {
//        for(int j = 0; j < 20; j++) {
//            cout << solve(i, j, 1) << " ";
//        }
//        cout << endl;
//    }

    int T;

    cin >> T;
    while(T--) {
        solve();
    }


}