#include <bits/stdc++.h>

using namespace std;

const int k_N = 4000 + 3;
const int k_K = 800 + 3;
const int k_Inf = 1e9 + 3;

int n, k;
int u[k_N][k_N];

int dp[2][k_N];

int get_sum(int l, int r){
    int answer = u[r][r];
    if(l){
        answer -= u[l - 1][r];
        answer -= u[r][l - 1];
        answer += u[l - 1][l - 1];
    }
    answer >>= 1;
    return answer;
}

void divide_and_conquer(int l, int r, int sl, int sr, int odd){
    if(l > r)
        return;

    int mid = (l + r) >> 1, opt = -1;
    dp[odd][mid] = k_Inf;
    for(int i = max(mid, sl); i <= sr; ++i){
        int curr = dp[!odd][i + 1] + get_sum(mid, i);
        if(curr <= dp[odd][mid]){
            dp[odd][mid] = curr;
            opt = i;
        }
    }

    divide_and_conquer(l, mid - 1, sl, opt, odd);
    divide_and_conquer(mid + 1, r, opt, sr, odd);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char c;
            cin >> c;
            u[i][j] = c - '0';
        }
    }

    for(int i = 1; i < n; ++i)
        for(int j = 0; j < n; ++j)
            u[i][j] += u[i - 1][j];

    for(int j = 1; j < n; ++j)
        for(int i = 0; i < n; ++i)
            u[i][j] += u[i][j - 1];

    for(int j = 0; j < n; ++j)
        dp[0][j] = k_Inf;
    dp[0][n] = 0;

    for(int i = 1; i <= k; ++i){
        divide_and_conquer(0, n - 1, 0, n - 1, i & 1);
        dp[i & 1][n] = k_Inf;
    }

    cout << dp[k & 1][0] << "\n";
}