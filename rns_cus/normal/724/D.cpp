#include <bits/stdc++.h>
using namespace std;

const int M = 200001;

char s[M];
char ans[M];
int vis[M];

int main() {
    ///freopen("d.in", "r", stdin);
    int m;
    scanf("%d %s", &m, s + 1);
    int n = strlen(s + 1);
    int len = 0;
    for(int i = 0; i < 26; i ++) {
        for(int j = 1; j <= n; j ++) vis[j] = 0;
        for(int j = 1; j <= n; j ++) if(s[j] <= 'a' + i) vis[j] = 1;
        int lv = 0;
        bool ok = 1;
        for(int j = 1; j <= n; j ++) {
            if(vis[j]) lv = j;
            else if(j - lv >= m) {ok = 0; break;}
        }
        if(!ok) continue;
        for(int j = 1; j <= n; j ++) vis[j] = 0;
        for(int j = 1; j <= n; j ++) if(s[j] < 'a' + i) {
            ans[len ++] = s[j];
            vis[j] = 1;
        }
        lv = 0;
        int last;
        for(int j = 1; j <= n; j ++) {
            if(vis[j]) lv = j;
            if(s[j] == 'a' + i) last = j;
            if(j == lv + m) {
                lv = last;
                ans[len ++] = 'a' + i;
            }
        }
        sort(ans, ans + len);
        cout << ans << endl;
        return 0;
    }
}