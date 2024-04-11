#include <bits/stdc++.h>
using namespace std;

int q;
int l, r, k;
int dp[1000050];
int dat[10][1000500];
int pro[1000050];

int get_pro(int i){
    if(pro[i] != -1) return pro[i];
    if(i < 10) return pro[i] = i;
    return pro[i] = (i % 10) == 0 ? get_pro(i/10) : (i % 10) * get_pro(i/10);
}

int get(int i){
    if(dp[i] != -1) return dp[i];
    if(i < 10) return dp[i] = i;

    return dp[i] = get(get_pro(i));
}

int main(){
    fill(dp,dp+1000050,-1);
    fill(pro,pro+1000050,-1);
    //for(int i = 0; i < 20; i++) cout << get(i) << endl;
    for(int i = 0; i < 10; i++) dat[i][0] = 0;
    for(int i = 1; i < 1000050; i++){
        for(int j = 0; j < 10; j++) dat[j][i] = dat[j][i-1];
        //cout << i << endl;
        dat[get(i)][i] ++;
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", dat[k][r] - dat[k][l-1]);
    }
}