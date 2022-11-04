#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 51, M = 9;

int t, n, m;

char s[N][M];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i]);
        int ans = 0x7fffffff;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++){
                int now = 0;
                for (int k = 0; k < m; k++){
                    int delta = abs(s[i][k] - s[j][k]);
                    now += delta;
                }
                ans = min(ans, now);
            }
        printf("%d\n", ans);
    }
    return 0;
}