#include <bits/stdc++.h>
using namespace std;

int n,m,k;
char c[2005][2005];

int main() {
    int ans = 0;
    int cnt = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> c[i][j], cnt += (c[i][j] == '.');
    if(k == 1) return !printf("%d", cnt);

    for(int i = 0; i < n; i++){
        int con = 0;
        for(int j = 0; j <= m; j++){
            if(j == m || c[i][j] == '*'){
                ans += (con >= k ? con - k + 1 : 0);
                con = 0;
            }
            else{
                con ++;
            }
        }
    }
    for(int j = 0; j < m; j++){
        int con = 0;
        for(int i = 0; i <= n; i++){
            if(i == n || c[i][j] == '*'){
                ans += (con >= k ? con - k + 1 : 0);
                con = 0;
            }
            else{
                con ++;
            }
        }
    }
    cout << ans;
}