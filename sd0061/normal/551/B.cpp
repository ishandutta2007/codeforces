#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

typedef long long LL;
char a[3][N];
int tmp[3][26];
int cnt[3][26];
void work() {
    int i , j , res = 0;
    for (i = 0 ; i < 3 ; ++ i) {
        scanf("%s" , a[i]);
        for (j = 0 ; a[i][j] ; ++ j)
            ++ cnt[i][a[i][j] - 'a'];
    }
    memcpy(tmp , cnt , sizeof(tmp));
    for (i = 0 ; i <= 100000 ; ++ i) {
        int x = 1 << 30;
        for (j = 0 ; j < 26 ; ++ j)
            if (cnt[2][j])
                x = min(x , cnt[0][j] / cnt[2][j]);
        res = max(res , i + x);
        for (j = 0 ; j < 26 ; ++ j) {
            cnt[0][j] -= cnt[1][j];
            if (cnt[0][j] < 0)
                break;
        }
        if (j < 26) break;
    }
    for (i = 0 ; i <= 100000 ; ++ i) {
        int x = 1 << 30;
        for (j = 0 ; j < 26 ; ++ j)
            if (tmp[2][j])
                x = min(x , tmp[0][j] / tmp[2][j]);
        if (i + x == res) {
            for (j = 0 ; j < i ; ++ j)
                printf("%s" , a[1]);
            for (j = 0 ; j < x ; ++ j)
                printf("%s" , a[2]);
            for (i = 0 ; i < 26 ; ++ i)
                for (j = 0 ; j < tmp[0][i] - x * tmp[2][i] ; ++ j)
                    putchar('a' + i);
            return;
        }
        for (j = 0 ; j < 26 ; ++ j) {
            tmp[0][j] -= tmp[1][j];
            if (tmp[0][j] < 0)
                break;
        }
        if (j < 26) break;
    }
}

int main() {
    work();
    return 0;
}