#include <iostream>
using namespace std;
int n, a[52][52], ans[52]; 
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int x = 1; x <= n; x ++) {

        for(int i = 1; i <= n; i ++) {
            int val = -1, ok = 0, j;

            for(j = 1; j <= n; j ++) {
                if(a[i][j]) {
                    ok = 1;
                    if(val == -1) val = a[i][j];
                    if(a[i][j] != val) break;
                }
            }

            if(j == n+1 && ok) {
                ans[i] = val; 
                //printf("%d %d %d\n", x, i, val);
                for(int k = 1; k <= n; k ++) {
                    if(a[i][k] >= val) a[i][k] = 0;
                    if(a[k][i] >= val) a[k][i] = 0;
                }
                break;
            }
        }

    }

    for(int i = 1; i <= n; i ++) {
        if(ans[i] == 0) ans[i] = n;
        printf("%d ", ans[i]);
    }
}