#include <iostream>
#include <cstring>
using namespace std;
int n, m;
char s[102][102];
int main() {
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) {
        scanf("%s", s[i]+1);
    }

    int min_x = 102, max_x = 0, min_y = 102, max_y = 0;
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i][j] == 'B') {
                min_x = min(i, min_x);
                max_x = max(i, max_x);
                min_y = min(j, min_y);
                max_y = max(j, max_y);
                cnt ++;
            }
        }
    }

    int ans = -1; 
    if(cnt == 0) {
        ans = 1;
    } else {
        int d = max(max_y - min_y, max_x - min_x) + 1;

        if(d <= n && d <= m) {
            ans = d * d - cnt;
        } 
    }
    printf("%d\n", ans);
}