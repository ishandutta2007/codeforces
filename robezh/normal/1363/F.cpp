#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const int N = 2005;
int n;
string s, t;
int dp[N][N];
int sufs[N][26], suft[N][26];

int solve(int l1, int l2) {
    if(dp[l1][l2] != -1) return dp[l1][l2];
    if(l1 == 0 && l2 == 0) return 0;
    int res = N;
    if(l1 >= 1) res = min(res, solve(l1 - 1, l2) + 1);
    if(l2 >= 1 && sufs[l1][t[l2 - 1] - 'a'] > suft[l2][t[l2 - 1] - 'a']) res = min(res, solve(l1, l2 - 1));
    if(l1 >= 1 && l2 >= 1 && s[l1 - 1] == t[l2 - 1]) res = min(res, solve(l1 - 1, l2 - 1));
    return dp[l1][l2] = res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> s >> t;
        rep(i, 0, n + 1) {
            fill(dp[i], dp[i] + n + 1, -1);
            fill(sufs[i], sufs[i] + 26, 0);
            fill(suft[i], suft[i] + 26, 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                sufs[i][j] = sufs[i + 1][j];
                suft[i][j] = suft[i + 1][j];
            }
            sufs[i][s[i] - 'a']++;
            suft[i][t[i] - 'a']++;
        }
        bool good = true;
        for (int j = 0; j < 26; j++) good &= (sufs[0][j] == suft[0][j]);
        if (!good) {
            cout << -1 << '\n';
            continue;
        }
        cout << solve(n, n) << '\n';
    }
}