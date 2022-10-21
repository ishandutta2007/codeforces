#include <bits/stdc++.h>
using namespace std;

const int N = 120, P2 = 1100000, INF = (int)1e9;

int n,m;
int val[N];
char mode[25];
int turn[25];
int cnt[P2], low[P2], dp[P2];


int main(){
    for(int i = 0; i < (1 << 20); i++){
        cnt[i] = 0;
        int j = i, pos = 0;
        while(j > 0){
            if(j % 2 == 1) low[i] = pos;
            cnt[i] += j % 2; j /= 2;
            pos++;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) cin >> val[i];
    sort(val, val+n, greater<int>());
    cin >> m;
    sort(val, val+m);
    for(int i = 0; i < m; i++){
        cin >> mode[i] >> turn[i];
    }

    for(int i = (1 << m) - 2; i >= 0; i--){
        if(turn[cnt[i]] == 1){
            dp[i] = -INF;
            for(int j = 0; j < m; j++){
                if(!(i & (1 << j))){
                    if(mode[cnt[i]] == 'b') dp[i] = max(dp[i], dp[i + (1 << j)]);
                    else dp[i] = max(dp[i], dp[i + (1 << j)] + val[j]);
                }
            }
        }
        else{
            dp[i] = INF;
            for(int j = 0; j < m; j++){
                if(!(i & (1 << j))){
                    if(mode[cnt[i]] == 'b') dp[i] = min(dp[i], dp[i + (1 << j)]);
                    else dp[i] = min(dp[i], dp[i + (1 << j)] - val[j]);
                }
            }
        }
    }
    //for(int i = 0; i < 4; i++) cout << dp[i] << " ";
    cout << dp[0] << endl;
}