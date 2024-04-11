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

const int N = 12, L = 120, M = 256;

int n;
int nxt[N][L][M];
int idx[N][L];
int loc[N][M][2];
int cnt[M];
string str[N];
int dp[M][1 << 10];
vi ncs;

int getnext(int c, int mask, int nc) {
    int nmask = 0;
    rep(i, 0, n) {
        int cur = loc[i][c][mask >> i & 1];
        int nx = nxt[i][cur][nc];
        if(nx == -1) {
            return -1;
        }
        nmask ^= (idx[i][nx] << i);
    }
    return nmask;
}

int solve(int c, int mask) {
//    cout << (char)c << " " << mask << endl;
    if(dp[c][mask] != -1) return dp[c][mask];
    int &res = dp[c][mask];
    res = 1;
    for (int nc : ncs) {
        int nmask = getnext(c, mask, nc);
        if(nmask != -1) {
            res = max(res, 1 + solve(nc, nmask));
        }
    }
    return res;
}

string recur(int c, int mask) {
    if(dp[c][mask] == 1) return char(c) + string("");
    for (int nc : ncs) {
        int nmask = getnext(c, mask, nc);
        if(nmask != -1 && 1 + dp[nc][nmask] == dp[c][mask]) {
            return (char)c + recur(nc, nmask);
        }
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (char c = 'a'; c <= 'z'; c++) ncs.push_back(c);
    for (char c = 'A'; c <= 'Z'; c++) ncs.push_back(c);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) {
            fill(idx[i], idx[i] + L, 0);
        }
        memset(nxt, -1, sizeof nxt);
        memset(loc, -1, sizeof loc);
        rep(i, 0, n) {
            cin >> str[i];
            memset(cnt, 0, sizeof cnt);
            rep(j, 0, sz(str[i])) {
                int c = str[i][j];
                loc[i][c][cnt[c]] = j;
//                cout << i << " " << char(c) << " " << cnt[c] << " " << j << endl;
                idx[i][j] = cnt[c]++;
            }
            for (int j = sz(str[i]) - 1; j >= 0; j--) {
                if(j == sz(str[i]) - 1) {
                    fill(nxt[i][j], nxt[i][j] + 256, -1);
                } else {
                    rep(k, 0, 256) nxt[i][j][k] = nxt[i][j + 1][k];
                    nxt[i][j][str[i][j + 1]] = j + 1;
                }
            }
        }
        memset(dp, -1, sizeof dp);

        int res = 0, mc = -1;
        for (char c : ncs) {
            bool has = true;
            rep(i, 0, n) has &= loc[i][c][0] != -1;
//            cout << c << " " << has << endl;
            if(has) {
                int cur = solve(c, 0);
                if(cur > res) {
                    res = cur;
                    mc = c;
                }
            }
        }
        cout << res << '\n';
        if(res == 0) cout << "" << '\n';
        else cout << recur(mc, 0) << '\n';
//        cout << res << '\n';
    }


}