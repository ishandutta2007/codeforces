#include<stdio.h>
#include<algorithm>
using namespace std;
int a[310][310], n, x, y, z, k;
long long sum;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) scanf("%d", &a[i][j]);
    scanf("%d", &k);
    for(int runs = 0; runs < k; runs ++){
        scanf("%d %d %d", &x, &y, &z);
        for(int i = 1; i <= n; i ++)for(int j = 1; j <= n; j ++){
            a[i][j] = min(a[i][j],min(a[i][y] + z + a[j][x], a[i][x] + z + a[j][y]));
        }
        sum = 0;
        for(int i = 1; i <= n; i ++) for(int j = i + 1; j <= n; j ++) sum += a[i][j];
        printf("%I64d ", sum);
    }puts("");
}