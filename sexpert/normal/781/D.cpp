#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> mat;
typedef bitset<505> BS;

mat TM[62], MT[62];
ll dp[62][505][2];
const ll INF = 1000000000LL * 1000000000LL;

mat mul(mat A, mat B) {
    BS ba[505], bb[505];
    int n = A.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ba[i][j] = A[i][j];
            bb[i][j] = B[j][i];
        }
    }
    mat res(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res[i][j] = ((ba[i] & bb[j]).count() > 0);

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int l = 0; l < 62; l++) {
        TM[l].assign(n, vector<int>(n));
        MT[l].assign(n, vector<int>(n));
    }
    for(int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        if(t == 0)
            TM[0][u - 1][v - 1]++;
        else
            MT[0][u - 1][v - 1]++;
    }
    for(int l = 1; l < 62; l++) {
        TM[l] = mul(TM[l - 1], MT[l - 1]);
        MT[l] = mul(MT[l - 1], TM[l - 1]);
    }
    /*for(int l = 0; l < 4; l++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << TM[l][i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << MT[l][i][j] << " ";
            }
            cout << '\n';
        }
        cout << "===\n";
    }*/
    for(int v = 0; v < n; v++) {
        dp[0][v][0] = dp[0][v][1] = 0;
        for(int i = 0; i < n; i++) {
            //cout << MT[0][v][i] << " ";
            dp[0][v][0] = max(dp[0][v][0], (ll)TM[0][v][i]);
            dp[0][v][1] = max(dp[0][v][1], (ll)MT[0][v][i]);
        }
        //cout << '\n';
    }
    //cout << "l = 0\n";
    //cout << dp[0][0][0] << " " << dp[0][0][1] << '\n';
    //cout << dp[0][1][0] << " " << dp[0][1][1] << '\n';
    for(int l = 1; l < 62; l++) {
        //cout << "l = " << l << '\n';
        for(int v = 0; v < n; v++) {
            ll def = 1LL << l;
            dp[l][v][0] = dp[l - 1][v][0];
            dp[l][v][1] = dp[l - 1][v][1];
            for(int i = 0; i < n; i++) {
                if(TM[l][v][i])
                    dp[l][v][0] = max(dp[l][v][0], def + dp[l - 1][i][1]);
                if(MT[l][v][i])
                    dp[l][v][1] = max(dp[l][v][1], def + dp[l - 1][i][0]);
            }
            //cout << dp[l][v][0] << " " << dp[l][v][1] << '\n';
        }
    }
    ll ans = 0;
    for(int l = 0; l < 62; l++)
        ans = max(ans, dp[l][0][0]);

    cout << (ans <= INF ? ans : -1) << '\n';
}