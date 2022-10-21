#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int n, m;
string str[55];
int vis[55][256];
int cnt = 0;
int usedcnt[55], bcnt[1 << 20];
char gp[(1 << 20)][55];
pii p[55];
ll uni[1 << 20];
bool fin[1 << 20];
ld dp[1 << 20][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < (1 << 20); i++) bcnt[i] = bcnt[i / 2] + i % 2;

    cin >> n;
    rep(i, 0, n) cin >> str[i];
    if(n == 1) return cout << 0 << endl, 0;
    m = sz(str[0]);
    fill(gp[0], gp[0] + n, 1);
    for(int mask = 1; mask < (1 << m); mask++) {
        int fir = 0;
        while(!(mask >> fir & 1)) fir++;
        int sub = mask ^ (1 << fir);
        for(int j = 0; j < n; j++) {
            int &new_gp = vis[gp[sub][j]][str[j][fir]];
            if(!new_gp) {
                new_gp = ++cnt;
                p[cnt] = {gp[sub][j], str[j][fir]};
            }
            gp[mask][j] = new_gp;
        }
        for(int j = 0; j < n; j++) usedcnt[gp[mask][j]]++;
        for(int j = 0; j < n; j++) {
            if(usedcnt[gp[mask][j]] == 1) uni[mask] |= (1LL << j);
        }
//        cout << bitset<10>(mask) << " " << bitset<10>(uni[mask]) << endl;

        for(int j = 0; j < n; j++) usedcnt[gp[mask][j]] = 0;
        for(int i = 1; i <= cnt; i++) vis[p[i].first][p[i].second] = 0;
        cnt = 0;
    }
    double res = 0;
    dp[0][0] = 1;
    for(int mask = 1; mask < (1 << m); mask++) {
        for(int j = 0; j < m; j++) {
            if(mask >> j & 1) {
                int sub = mask ^ (1 << j);
                ld p0 = (dp[sub][0] - dp[sub][1]) * ((ld)1 / (m - bcnt[sub]));
                dp[mask][0] += p0;
                ll mulsub = ((1LL << n) - 1) ^ uni[sub];
                if(mulsub) {
//                    cout << mask << ", " << j << ": " << mulsub << " " << uni[sub] <<  endl;
                    dp[mask][1] += p0 * (ld)__builtin_popcountll(uni[mask] & mulsub) / __builtin_popcountll(mulsub);
                }
            }
        }
//        cout << mask << ',' << dp[mask][0] << " " << dp[mask][1] << endl;
        res += dp[mask][1] * bcnt[mask];
    }
    cout << fixed << setprecision(12) << res << '\n';


}