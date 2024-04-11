#include <bits/stdc++.h>
using namespace std;

const int N = 705;

int gcd(int x, int y){
    return x == 0 ? y : gcd(y % x, x);
}

int n;
int num[N];
bool good[N][N];
bool dp[N][N];
bool dpl[N][N], dpr[N][N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) good[i][j] = (gcd(num[i], num[j]) > 1);
    }
    for(int i = 0; i < n; i++) dpl[i][i] = dpr[i][i] = 1;
    for(int inter = 0; inter < n; inter ++){
        for(int l = 0; l + inter < n; l++){
            int r = l + inter;
            for(int mid = l; mid <= r; mid++){
                bool ok = dpl[l][mid] && dpr[mid][r];
                if(r+1 < n) dpl[l][r+1] |= ok && good[mid][r+1];
                if(l > 0) dpr[l-1][r] |= ok && good[l-1][mid];
                dp[l][r] |= ok;
            }
        }
    }
    if(dp[0][n-1]) cout << "Yes" << endl;
    else cout << "No" << endl;



}