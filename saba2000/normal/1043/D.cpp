#include<bits/stdc++.h>
using namespace std;
int a[12][150009];
int f[150009];
int p[150009];
main(){
    int n, m;
    cin >> n>> m;
    for(int i = 0; i < m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        p[a[0][i]] = i, f[i] = n - i + 1;
    for(int i = 1; i < m; i++){
        for(int j = 1; j <= n; j++)
            a[i][j] = p[a[i][j]];
        int cnt = 1;
        for(int j = 2; j <= n; j++){
            if(a[i][j] == a[i][j - 1] + 1) cnt++;
            else{
                for(int k = j - cnt; k < j; k++)
                    f[a[i][k]] = min(f[a[i][k]], j - k);
                cnt = 1;
            }
        }
        for(int k = n - cnt + 1; k <= n; k++)
            f[a[i][k]] = min(f[a[i][k]], n + 1 - k);
    }
    for(int i = 1; i <= n; i++)
        ans += f[i];
    cout << ans << endl;
}