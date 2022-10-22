#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 30005;
const int M = 300;
int n , d , cnt[N];
int f[N][M + M + 1];

void work() {
    int i , j , x;
    scanf("%d%d",&n,&d);
    for (i = 0 ; i < n ; ++ i) {
    scanf("%d",&x);
    ++ cnt[x];
    }
    memset(f , 0xC0 , sizeof(f));
    f[d][M] = 0;
    int res = 0;
    for (i = d ; i <= 30000 ; ++ i) {
    for (j = -M ; j <= M  ; ++ j) {
        if (f[i][j + M] < 0)
        continue;
        f[i][j + M] += cnt[i];
        res = max(res , f[i][j + M]);
        if (d + j > 1 && i + d + j - 1 <= 30000) {
        f[i + d + j - 1][j + M - 1] = max(f[i + d + j - 1][j + M - 1] , f[i][j + M]);
        }
        if (i + d + j <= 30000) {
        f[i + d + j][j + M] = max(f[i + d + j][j + M] , f[i][j + M]);
        }
        if (j < M && i + d + j + 1 <= 30000) {
        f[i + d + j + 1][j + M + 1] = max(f[i + d + j + 1][j + M + 1] , f[i][j + M]);
        }
    }
    }
    cout << res << endl;
}

int main() {
    //int _;
    //scanf("%d",&_);
    // while (_ --)
    work();

    return 0;
}