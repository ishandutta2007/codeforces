#include <bits/stdc++.h>
using namespace std;

const int N = (int)12, M = (int)1e5 + 500;
typedef long long ll;

int n,m;
int a[N][M];
int loc[N][M];
int dp[M];

int get_nxt(int i, int num){
    if(loc[i][num] == m - 1) return -1;
    else return a[i][loc[i][num] + 1];
}

int get(int num){
    if(dp[num] != -1) return dp[num];

    dp[num] = 1;
    int nxt_num = get_nxt(0, num);
    for(int t = 0; t < n; t++){
        int cur_num = get_nxt(t, num);
        if(cur_num == -1 || cur_num != nxt_num) return dp[num];
    }
    return dp[num] = 1 + get(nxt_num);

}


int main(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]), a[i][j]--;
            loc[i][a[i][j]] = j;
        }
    }
    memset(dp, -1, sizeof(dp));

    ll res = 0;
    for(int i = 0; i < m; i++){
        res += get(i);
    }
    cout << res << endl;
}