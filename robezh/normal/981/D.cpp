#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;
ll num[55];
ll psum[55], pw2[65];
bool dp[55][55];
ll res = 0;
ll cur = 0;

ll ps(int l, int r){
    return psum[r] - psum[l-1];
}

bool sati(int l, int r){
    ll now = psum[r] - psum[l-1];
    return (now & cur) == cur;
}

ll check(){
    ll res = 0;
    for(int i = 1; i <= n-2; i++){
        for(int j = i+1; j <= n-1; j++){
            for(int k = j+1; k <= n; k++){
                for(int t = k+1; t <= n; t++){
                    res = max(res, ps(1,i) & ps(i+1,j) & ps(j+1, k) & ps(k+1, t) & ps(t+1, n));
                }

            }
        }
    }
    return res;
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> num[i];
    pw2[0] = 1; for(int i = 1; i < 65; i++) pw2[i] = 2 * pw2[i-1];
    psum[0] = 0;
    for(int i = 1; i <= n; i++){
        psum[i] = psum[i-1] + num[i];
    }
    int curi = 60;
    while(curi >= 0){
        for(int i = 0; i < 55; i++) fill(dp[i], dp[i]+55, false);
        cur = res + pw2[curi];
        dp[0][0] = true;
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= j; k++){
                    dp[i][j] |= (dp[i-1][j-k] & sati(j-k+1, j));
                }
            }
        }
        if(dp[k][n]) res = cur;

        curi --;
    }

    cout << res << endl;
}