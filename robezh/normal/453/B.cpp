#include <bits/stdc++.h>
using namespace std;

#define INF 10000050
#define MAXS 132000

int n;
int dp[105][MAXS];
int re[105][MAXS];
int num[105];

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
vector<int> V;
int fact[61] = {131071, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5, 16, 3, 32, 9,
                6, 1, 64, 3, 128, 5, 10, 17, 256, 3, 4, 33, 2, 9, 512,
                7, 1024, 1, 18, 65, 12, 3, 2048, 129, 34, 5, 4096, 11,
                8192, 17, 6, 257, 16384, 3, 8, 5, 66, 33, 32768, 3, 20,
                9, 130, 513, 65536, 7};

bool not_inter(int x, int S){
    return (x^S) == (x+S);
}

void set_V(){
    for(int t = 0; t <= 60; t++){
        int res = 0;
        for(int i = 16; i >= 0; i--){
            res *= 2;
            if(t % prime[i] == 0) res++;
        }
        V.push_back(res);
    }
    for(int i = 0; i < V.size(); i++){
        cout << V[i] << ", ";
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    for(int i = 0; i < n; i++) fill(dp[i], dp[i]+132000, INF);
    for(int i = 1; i <= 60; i++){
        if(abs(i-num[0]) < dp[0][fact[i]]){
            dp[0][fact[i]] = abs(i-num[0]);
            re[0][fact[i]] = i;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= 60; j++){
            for(int t = 0; t < (1<<17-1); t++){
                if(not_inter(fact[j], t)){
                    if(dp[i-1][t]+abs(j-num[i]) < dp[i][fact[j]+t]){
                        dp[i][fact[j]+t] = dp[i-1][t] + abs(j-num[i]);
                        re[i][fact[j]+t] = j;
                    }
                }
            }
        }
    }
    int res = INF;
    int S;
    for(int j = 0; j < (1<<17-1); j++){
        if(dp[n-1][j] < res){
            res = dp[n-1][j];
            S = j;
        }
    }
    for(int i = n-1; i >= 0; i--){
        V.push_back(re[i][S]);
        S -= fact[re[i][S]];
    }
//    cout << res << endl;
    for(int i = V.size()-1; i >= 0; i--){
        cout << V[i] << " ";
    }
}