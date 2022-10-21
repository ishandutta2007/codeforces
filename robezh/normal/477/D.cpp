#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 5005, mod = (int)1e9 + 7, INF = (int)1e9;

int n;
string str;
int lcp[N][N];
int dp[N][N], ssum[N], pt[N];
int mn[N][N], smn[N];

bool leq(int l, int mid, int r) {
    // [l, mid] <= (mid, r]
    int len1 = mid - l  + 1, len2 = r - mid;
    if(len1 != len2) return len1 < len2;

    int cp = lcp[l][mid + 1];
    return cp >= len1 || str[l + cp] < str[mid + 1 + cp];
}

int make_val(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i++) res = (res * 2 + (str[i] - '0')) % mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    n = str.length();
    str = " " + str;

    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if(str[i] == str[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else lcp[i][j] = 0;
        }
    }
    rep(i, 1, n + 1) pt[i] = i + 1, smn[i] = INF;

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1;
        mn[0][i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            if(str[j + 1] == '0') continue;
            while(pt[j] > 1 && leq(pt[j] - 1, j, i)) {
                pt[j]--;
                if(str[pt[j]] == '1') {
                    ssum[j] = (ssum[j] + dp[pt[j] - 1][j]) % mod;
                    smn[j] = min(smn[j], mn[pt[j] - 1][j]);
//                    cout << "update " << pt[j] - 1 << " " << j << " " << dp[pt[j] - 1][j] << endl;
                }
            }
        }
        for (int j = 1; j <= i - 1; j++) {
            if(str[j + 1] == '0') continue;
            dp[j][i] = ssum[j];
            mn[j][i] = smn[j] + 1;
//            cout << j << " " << i << ": " << pt[j] << " " << smn[j] << " " << mn[j][i] << endl;
        }
    }
    rep(i, 0, n) sum = (sum + dp[i][n]) % mod;

    int mnval = INF;
    for(int la = n - 1; la >= n - 20 && la >= 0; la--) {
        if(str[la + 1] == '1') {
            mnval = min(mnval, make_val(la + 1, n) + mn[la][n]);
//            cout << la << " " << mn[la][n] << " " <<  make_val(la + 1, n) + mn[la][n] << endl;
        }
    }
    if(mnval == INF) {
        for(int la = n - 1; la >= 0; la--) {
            if(str[la + 1] == '1' && mn[la][n] < INF) {
                mnval = (make_val(la + 1, n) + mn[la][n]) % mod;
                break;
            }
        }
    }
    cout << sum << '\n';
    cout << mnval << '\n';



}