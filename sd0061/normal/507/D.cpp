#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;

int n , K , m;
int f[1005][105][4];

void work() {
    scanf("%d%d%d",&n,&K,&m);
    f[n][0][0] = 1;
    int i , j , k , l , x;
    x = 1;
    for (i = n ; i > 0 ; -- i) {
        for (j = 0 ; j < K ; ++ j) {
            for (k = 0 ; k < 4 ; ++ k) {
                if (!f[i][j][k]) continue;
                for (l = (i == 1) ? 1 : 0 ; l < 10 ; ++ l) {
                    int y = (j + x * l) % K;
                    if (y == 0 && l) {
                        f[i - 1][y][k | 2 | (l > 0)] += f[i][j][k];
                        f[i - 1][y][k | 2 | (l > 0)] %= m;
                    } else {
                        f[i - 1][y][k | (l > 0)] += f[i][j][k];
                        f[i - 1][y][k | (l > 0)] %= m;
                    }
                }
            }
        }
        x *= 10 , x %= K;
    }
    int res = 0;
    for (i = 0 ; i < K ; ++ i) {
        res += f[0][i][3];
        res %= m;
    }
    cout << res << endl;
}

int main()
{
        work();
    return 0;
}