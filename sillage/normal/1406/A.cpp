#include<bits/stdc++.h>
using namespace std;
int a[200010];
int vis[110];
void solve(){
    int n;
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vis[a[i]]++;
    int cnt = 2, ans = 0;
    for (int i = 0; i <= 100; i++){
        cnt = min(cnt, vis[i]);
        ans += cnt;
    }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        solve();
    }
}