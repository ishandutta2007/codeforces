#include<bits/stdc++.h>
using namespace std;
int t,n,p[5005];
int x[5005][5005], y[5005][5005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                x[i][j] = y[i][j] = 0;
            }
        for (int i = 1; i <= n; i++){
            scanf("%d", &p[i]);
        }
        for (int b = 2; b + 1 < n; b++){
            for (int c = n - 1; c > b; c--){
                x[b][c] = x[b][c + 1] + (p[b] > p[c + 1]);
            }
        }
        for (int c = n - 1; c > 2; c--){
            for (int b = 2; b < c; b++){
                y[b][c] = y[b - 1][c] + (p[c] > p[b - 1]);
            }
        }
        long long ans = 0;
        for (int b = 2; b + 1 < n; b++)
            for (int c = n - 1; c > b; c--)
                ans += 1ll * x[b][c] * y[b][c];
        printf("%lld\n", ans);
    }
    return 0;
}