#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 30005;

int n , K , a[N];
LL f[N][205][2][2];

inline void update(LL& A , LL B) {
    if (A < B)
        A = B;
}

void work() {
    int i , j ;
    scanf("%d%d",&n,&K);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    memset(f , 0xC0 , sizeof(f));

    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= K ; ++ j) {
            int x = ((j == 1 || j == K) ? 1 : 2) * a[i];

            if (j == 1) f[i][j][0][0] = x;
            update(f[i][j][0][0] , f[i - 1][j][0][0] + x);
            update(f[i][j][0][0] , f[i - 1][j - 1][1][0] + x);
            update(f[i][j][0][0] , f[i - 1][j - 1][1][1] + x);

            if (j == 1) f[i][j][1][0] = -x;
            update(f[i][j][1][0] , f[i - 1][j][1][0] - x);
            update(f[i][j][1][0] , f[i - 1][j - 1][0][0] - x);
            update(f[i][j][1][0] , f[i - 1][j - 1][0][1] - x);

            update(f[i][j][0][1] , f[i - 1][j][0][1]);
            update(f[i][j][0][1] , f[i - 1][j - 1][0][1]);
            update(f[i][j][0][1] , f[i - 1][j - 1][0][0]);

            update(f[i][j][1][1] , f[i - 1][j][1][1]);
            update(f[i][j][1][1] , f[i - 1][j - 1][1][1]);
            update(f[i][j][1][1] , f[i - 1][j - 1][1][0]);
        }
    }

    LL res = 0;
    for (i = 1 ; i <= n ; ++ i) {
        update(res , f[i][K][0][0]);
        update(res , f[i][K][1][0]);
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}