#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 500;

int n, k;
int num[MAXN];
int dp[280];

int low(int i){
    for(int t = max(0, i-(k-1)); t <= i-1; t++){
        if(dp[t] == -1){
            return t;
        }else if(dp[t] >= max(0, i-(k-1))){
            return dp[t];
        }
    }
    return i;
}

int get(int i){
    if(dp[i] != -1) return dp[i];
    int l = low(i);
    for(int j = l; j <= i; j++){
        dp[j] = l;
    }
    return l;
}


int main(){
    fill(dp, dp+280, -1);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", get(num[i]));
    }
}