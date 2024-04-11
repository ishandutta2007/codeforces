#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
int m;
ll dp[30000][105][2];
int now[10];
int pro[10], rem[20];

ll dfs(int i, int j, int dig){
    if(dp[i][j][0] != -1) return dp[i][j][0];
    ll res = 0, res1 = 0;
    for(int t = 0; t < 10; t++){
        if(now[t] > 0){
            now[t]--;
            ll nxt = dfs(i-pro[t], ((j-rem[dig]*t)%m+m)%m, dig-1);
            res += nxt;
            if(t != 0) res1 += nxt;
            now[t]++;
        }
    }
    dp[i][j][0] = res, dp[i][j][1] = res1;
    return res;
}

int main(){
    for(int i = 0; i < 30000; i++)
        for(int j = 0; j < 105; j++)
            dp[i][j][0] = dp[i][j][1] = -1;
    dp[0][0][0] = 1, dp[0][0][1] = 0;
    for(int j = 1; j < 105; j++)
        dp[0][j][0] = dp[0][j][1] = 0;
    fill(now, now+10, 0);
    cin >> n >> m;
    ll k = n;
    while(k > 0){now[k%10]++, k/=10;}
    for(int i = 0; i < 10; i++)
        pro[i] = (i == 0 ? 1 : (now[i-1]+1) * pro[i-1]);
    int p = 1;
    for(int i = 0; i < 20; i++){rem[i] = p; p*=10, p%=m;}

    int digit = 0, tot = pro[9] * (now[9]+1)-1;
    for(int i = 0; i < 10; i++) digit += now[i];

    dfs(tot, 0, digit-1);
    cout << dp[tot][0][1];
    
    return 0;
}