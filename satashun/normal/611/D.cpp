#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MOD = 1000000007;

int n;
string s;
int dp[5010][5010];
int df[5010][5010];

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

bool cmp(int i, int j, int k) { //s[i, j-1], s[j][k]
    int la = j - i, lb = k - j + 1;
    if (la < lb) return 1;
    if (la > lb) return 0;

    if (df[i][j] >= la) return 0;
    int p1 = i + df[i][j];
    int p2 = j + df[i][j];

    return s[p1] < s[p2];
}

int main() {
    cin >> n >> s;
    rep(i, n) dp[0][i] = 1;
    rep(i, n) df[n-1][i] = df[i][n-1] = (s[i] == s[n-1] ? 1 : 0);

    for (int i = n-2; i >= 0; --i) {
        for (int j = n-2; j >= 0; --j) {
            df[i][j] = (s[i] == s[j] ? df[i+1][j+1] + 1 : 0);
        }
    }

    for (int i = 1; i < n; ++i) {
        if (s[i] == '0') continue;
        int ac = 0;
        int piv = i-1;

        for (int j = i; j < n; ++j) { //s[i, j]
            while (piv >= 0 && cmp(piv, i, j)) {
                add(ac, dp[piv][i-1]);
                --piv;
            }

            dp[i][j] = ac;
        }
    }
    
    int ret = 0;
    rep(i, n) add(ret, dp[i][n-1]);
    cout << ret << endl;

    return 0;
}