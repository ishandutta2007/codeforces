#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N = 1e5 + 3;
const int MAX = 1000 + 3;
const int INF = 1e9;

ld dp[N][10];
int n, d, a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int j = 0; j < 10; ++j)
        dp[n][j] = (j == d) ? 0 : -INF;
    for(int i = n - 1; i >= 0; --i)
        for(int j = 0; j < 10; ++j){
            dp[i][j] = -INF;
            dp[i][j] = max(dp[i + 1][(j * a[i]) % 10] + log(a[i]), dp[i][j]);
            dp[i][j] = max(dp[i + 1][j], dp[i][j]);
        }
    //cout << dp[0][1] << " dp[i][j]" << endl;
    int i = 0, j = 1;
    vector<int> ans;
    while(i != n){
        if(dp[i + 1][(j * a[i]) % 10] + log(a[i]) >= dp[i + 1][j]){
            ans.push_back(i);
            j = j * a[i] % 10;
            ++i;
        }
        else ++i;
    }
    if(j != d || ans.empty()){
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << "\n";
    for(int x: ans)
        cout << a[x] << " ";
    cout << "\n";
}