#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 55;

int S , g[N][N] , lx[N] , ly[N] , match[N] , ans , slack[N];
int res[N];
bool fx[N] , fy[N];

bool find(int x) {
    fx[x] = 1;
    for (int y = 1 ; y <= S ; ++ y) {
        if (fy[y]) continue;
        if (lx[x] + ly[y] == g[x][y]) {
            fy[y] = 1;
            if (!match[y] || find(match[y])) {
                match[y] = x;
                res[x] = y;
                return 1;
            }
        } else {
            slack[y] = min(slack[y] , lx[x] + ly[y] - g[x][y]);
        }
    }
    return 0;
}

void update() {
    int delta = 1 << 30 , i;
    for (i = 1 ; i <= S ; ++ i)
        if (!fy[i])
            delta = min(delta , slack[i]);
    for (i = 1 ; i <= S ; ++ i) {
        if (fx[i]) lx[i] -= delta;
        if (fy[i]) ly[i] += delta;
        slack[i] -= delta;
    }
}

void Kuhn_Munkras() {
    int i , j;
    for (i = 1 ; i <= S ; ++ i) {
        match[i] = lx[i] = ly[i] = 0;
        for (j = 1 ; j <= S ; ++ j)
            lx[i] = max(lx[i] , g[i][j]);
    }
    for (i = 1 ; i <= S ; ++ i) {
        while (1) {
            for (j = 1 ; j <= S ; ++ j)
                fx[j] = fy[j] = 0 , slack[j] = 1 << 30;
            if (find(i))
                break;
            else
                update();
        }
    }
}

int n , K;
char A[2000005];
char B[2000005];

void work() {
    scanf("%d%d%s%s",&n,&K,A,B);
    for (int i = 0 ; i < n ; ++ i) {
        int x = isupper(A[i]) ? A[i] - 'A' + 27 : A[i] - 'a' + 1;
        int y = isupper(B[i]) ? B[i] - 'A' + 27 : B[i] - 'a' + 1;
        ++ g[x][y];
    }
    S = K;
    Kuhn_Munkras();
    ans = 0;
    for (int i = 1 ; i <= S ; ++ i) {
        ans += g[i][res[i]];
    }
    printf("%d\n" , ans);
    for (int i = 1 ; i <= S ; ++ i) {
        if (res[i] <= 26)
            printf("%c" , res[i] - 1 + 'a');
        else
            printf("%c" , res[i] - 27 + 'A');
    }
}

int main() {
    work();
    return 0;
}