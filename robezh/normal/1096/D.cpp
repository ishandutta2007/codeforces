#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;
const ll INF = (ll)1e18;

int n;
string s;
string str = "hard";
ll dp[N][5], a[N];

int nxt(int i, char c){
    if(i == 4) return 4;
    return i < 4 && (str[i] == c) ? i + 1 : i;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();


    for(int i = 0; i < N; i++) fill(dp[i], dp[i] + 5, INF);

    cin >> n;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 0;
//    cout << "ok2" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            int nx = nxt(j, s[i]);
            if(nx != 4) dp[i][nx] = min(dp[i][nx], dp[i-1][j]);
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i]);
        }
    }
    ll res = INF;
    for(int j = 0; j < 4; j++){
        res = min(res, dp[n][j]);
    }
    cout << res << endl;
}