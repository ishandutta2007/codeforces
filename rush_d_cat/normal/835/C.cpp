#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

int sum[12][102][102];
int cnt[12][102][102];

int n, q, c;
int x[100002], y[100002], s[100002];
int t, cx1, cy1, cx2, cy2;

int main() {
    
    scanf("%d %d %d", &n, &q, &c);

    for(int i=1;i<=n;i++) {
        scanf("%d %d %d", &x[i], &y[i], &s[i]);
        cnt[s[i]][x[i]][y[i]] ++;
    }

    for(int i=0;i<=c;i++) {
        for(int x=1;x<=100;x++) {
            for(int y=1;y<=100;y++) {
                sum[i][x][y] = sum[i][x][y-1] + sum[i][x-1][y] - sum[i][x-1][y-1]
                + cnt[i][x][y];
            }
        }
    }

    for(int test=1;test<=q;test++) {
        scanf("%d %d %d %d %d", &t, &cx1, &cy1, &cx2, &cy2);

        int res = 0;
        for(int i=0;i<=c;i++) {
            int cur = (i + t) % (c + 1); 
            res += cur * (sum[i][cx2][cy2] - sum[i][cx1-1][cy2] - sum[i][cx2][cy1-1] + sum[i][cx1-1][cy1-1]); 
        }

        printf("%d\n", res);
    }

}