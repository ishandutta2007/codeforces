#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 3;

int n, m;
int dp[2][N][N];
string a, b;

int get_dp(int s, int i, int j){
    if(i == n || j == m) return 0;
    return dp[s][i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> a >> b;

    for(int s = 1; s >= 0; --s){
        for(int i = n - 1; i >= 0; --i){
            for(int j = m - 1; j >= 0; --j){
                int &ans = dp[s][i][j];
                ans = 0;

                if(a[i] == b[j])
                    ans = max(ans, 2 + get_dp(true, i + 1, j + 1));
                if(s){
                    ans = max(ans, -1 + get_dp(true, i + 1, j));
                    ans = max(ans, -1 + get_dp(true, i, j + 1));
                }
                else{
                    ans = max(ans, get_dp(false, i, j + 1));
                    ans = max(ans, get_dp(false, i + 1, j));
                }
            }
        }
    }

    cout << dp[0][0][0] << "\n";
}