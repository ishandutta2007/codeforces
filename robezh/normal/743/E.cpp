#include <bits/stdc++.h>
using namespace std;

const int N = 1050;

int n;
int num[N], dp[N][260];
int nxt[2][8][N];

int check(int d){
    for(int t = 0; t < 2; t++){
        d += t;
        for(int i = 0; i < 8; i++){
            int r = 0, cnt = 0;
            while(cnt < d && r < n){
                if(num[r] == i) cnt++;
                r++;
            }
            for(int j = 0; j < n; j++){
                nxt[t][i][j] = (cnt == d ? r : -1);
                if(num[j] == i){
                    cnt --;
                    while(cnt < d && r < n){
                        if(num[r] == i) cnt++;
                        r++;
                    }
                }
            }
        }
        d -= t;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (1 << 8); j++){
            if(dp[i][j] == -1) continue;
            for(int t = 0; t < 8; t++){
                if(!(j & (1 << t)) && nxt[0][t][i] != -1 && d != 0)
                    dp[nxt[0][t][i]][j + (1 << t)] = max(dp[nxt[0][t][i]][j + (1 << t)], dp[i][j] + d);
                if(!(j & (1 << t)) && nxt[1][t][i] != -1)
                    dp[nxt[1][t][i]][j + (1 << t)] = max(dp[nxt[1][t][i]][j + (1 << t)], dp[i][j] + d + 1);
            }
        }
        for(int j = 0; j < (1 << 8); j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
    if(d == 0){
        int res = 0;
        for(int i = 0; i < (1 << 8); i++) res = max(res, dp[n][i]);
        return res;
    }
    else {
        return dp[n][(1 << 8) - 1];
    }

}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i], num[i]--;
    int l = 0, r = 150, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(mid) > 0) l = mid;
        else r = mid;
    }
    cout << check(l) << endl;
}