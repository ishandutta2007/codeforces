#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 500 + 3;
const int K2 = 10 + 3;
const int INF = 1e9;

int n, m, k;
int e1[N][N], e2[N][N];
int dp[K2][N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    if(k & 1){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                cout << "-1 ";
            cout << "\n";
        }
        return 0;
    }
    k >>= 1;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m - 1; ++j)
            cin >> e1[i][j];
    for(int i = 0; i < n - 1; ++i)
        for(int j = 0; j < m; ++j)
            cin >> e2[i][j];

    //za rem = 0 si e 0
    for(int rem = 1; rem <= k; ++rem){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int &ans = dp[rem][i][j];
                ans = INF;
                if(i) check_min(ans, dp[rem - 1][i - 1][j] + e2[i - 1][j]);
                if(i != n - 1) check_min(ans, dp[rem - 1][i + 1][j] + e2[i][j]);
                if(j) check_min(ans, dp[rem - 1][i][j - 1] + e1[i][j - 1]);
                if(j != m - 1) check_min(ans, dp[rem - 1][i][j + 1] + e1[i][j]);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << dp[k][i][j] * 2 << " ";
        }
        cout << "\n";
    }
}