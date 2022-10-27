#include <iostream>
using namespace std;
const int N = 200000+10;
const int INF = 1e9+7;
int n,x1[N],y1[N],x2[N],y2[N];
int x_mx[N][2],x_mn[N][2],y_mx[N][2],y_mn[N][2];

int main() {
    scanf("%d",&n);
    x_mx[0][0] = -INF, x_mn[0][0] = INF;
    y_mx[0][0] = -INF, y_mn[0][0] = INF;
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
        x_mx[i][0] = max(x_mx[i-1][0], x1[i]);
        x_mn[i][0] = min(x_mn[i-1][0], x2[i]); 
        y_mx[i][0] = max(y_mx[i-1][0], y1[i]);
        y_mn[i][0] = min(y_mn[i-1][0], y2[i]); 
    }
    x_mx[n+1][1] = -INF, x_mn[n+1][1] = INF;
    y_mx[n+1][1] = -INF, y_mn[n+1][1] = INF;
    for(int i=n;i>=1;i--) {
        x_mx[i][1] = max(x_mx[i+1][1], x1[i]);
        x_mn[i][1] = min(x_mn[i+1][1], x2[i]); 
        y_mx[i][1] = max(y_mx[i+1][1], y1[i]);
        y_mn[i][1] = min(y_mn[i+1][1], y2[i]); 
    }
    for(int i=1;i<=n;i++) {
        int x_1 = max(x_mx[i-1][0], x_mx[i+1][1]);
        int x_2 = min(x_mn[i-1][0], x_mn[i+1][1]);
        int y_1 = max(y_mx[i-1][0], y_mx[i+1][1]);
        int y_2 = min(y_mn[i-1][0], y_mn[i+1][1]);
        if (x_1 <= x_2 && y_1 <= y_2) {
            printf("%d %d\n", x_1, y_1); return 0;
        }
    }
}