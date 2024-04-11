#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string s;
int num[505], sum = 0;
int psum[505][505];
int lc[505][505], rc[505][505];
int ms[505][505], dp[505][505];

int main(){
    fill(num, num+505, 0);
    for(int i = 0; i < 505; i++)for(int j = 0; j < 505; j++){
            lc[i][j] = rc[i][j] = ms[i][j] = dp[i][j] = psum[i][j] = 0;
        }

    scanf("%d%d%d", &n, &m, &k);
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, s);
        for(int j = 0; j < m; j++) if(s[j] == '1') psum[i][num[i]++] = j;
        if(num[i] == 0) continue;
        for(int j = 1; j <= num[i]-1; j++){
            for(int t = 0; t <= j; t++){
                ms[i][j] = max(ms[i][j], psum[i][t] - psum[i][0] + psum[i][num[i]-1] - psum[i][num[i]-1-(j-t)]);
            }
        }
        ms[i][num[i]] = psum[i][num[i]-1] - psum[i][0] + 1;
        //for(int j = num[i] + 1; j < 505; j++){ms[i][j] = ms[i][num[i]];}
        sum += ms[i][num[i]];
    }

    //for(int i = 0; i < 10; i++) cout << ms[0][i] << " ";

    for(int j = 0; j <= 500; j++) dp[0][j] = max((j == 0 ? 0 : dp[0][j-1]), ms[0][j]);
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= 500; j++){
            if(j != 0) dp[i][j] = dp[i][j-1];
            for(int t = 0; t <= j; t++){
                dp[i][j] = max(dp[i][j], dp[i-1][j-t] + ms[i][t]);
            }
        }
    }
    cout << sum - dp[n-1][k];
}