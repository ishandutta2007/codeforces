#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;

const int N = 1005;
int n , m , T;
char s[N][N];
int cnt[N][N];
int L[N] , R[N] , U[N] , D[N];
int sx , sy;
int ans = 1 << 30;

bool check(int X , int Y) {
    if (X * Y >= ans) return 0;
    int i , j  , x = sx , y = sy;
    int dx = 0 , dy = 0; ++ T;
    for (i = 0 ; i < X ; ++ i)
        for (j = 0 ; j < Y ; ++ j)
            if (s[x + i][y + j] != 'X') {
                return 0;
            } else {
                cnt[x + i][y + j] = T;
            }
    while (1) {
        bool f1 = 0 , f2 = 0;
        for (i = 0 ; i < X && !f1 ; ++ i)
            if (s[x + i][y + Y] == 'X')
                f1 = 1;
        for (i = 0 ; i < X ; ++ i)
            if (s[x + i][y + Y] != 'X')
                break;
        for (j = 0 ; j < Y && !f2 ; ++ j)
            if (s[x + X][y + j] == 'X')
                f2 = 1;
        for (j = 0 ; j < Y ; ++ j)
            if (s[x + X][y + j] != 'X')
                break;
        if (i >= X && j >= Y)
            return 0;
        if (i < X && j < Y && !f1 && !f2)
            break;
        if (i >= X) {
            for (i = 0 ; i < X ; ++ i)
                cnt[x + i][y + Y] = T;
            ++ y , ++ dy;
            continue;
        }
        if (j >= Y) {
            for (j = 0 ; j < Y ; ++ j)
                cnt[x + X][y + j] = T;
            ++ x , ++ dx;
            continue;
        }
        return 0;
    }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] == 'X' && T != cnt[i][j] || s[i][j] != 'X' && T == cnt[i][j])
                return 0;
 /*   for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j)
            printf("%d" , cnt[i][j]);
        puts("");
    }*/
    //printf("%d %d\n" , X , Y);
    if (!dx && !dy)
        ans = min(ans , min(X , Y));
    ans = min(ans , X * Y);
    return 1;
}

int main() {
   // freopen("~input.txt" , "r" , stdin);

    int i , j ;
    scanf("%d%d",&n,&m);
    int X = 1 << 30 , Y = 1 << 30;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        L[i] = 1 << 30 , R[i] = -1 << 30;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j) {
            if (s[i][j] == 'X') {
                L[i] = min(L[i] , j);
                R[i] = max(R[i] , j);
            }
        }
        bool flag = 0;
        for (j = L[i] ; j <= R[i] ; ++ j)
            if (s[i][j] != 'X')
                flag = 1;
        if (flag) {
            puts("-1");
            return 0;
        }
        if (L[i] <= R[i])
            Y = min(Y , R[i] - L[i] + 1);
    }
    for (i = 2 ; i <= n ; ++ i) {
        if (L[i] != 1 << 30 && L[i - 1] != 1 << 30) {
            int l = max(L[i] , L[i - 1]);
            int r = min(R[i] , R[i - 1]);
            Y = min(Y , r - l + 1);
        }
    }

    for (i = 1 ; i <= m ; ++ i)
        D[i] = 1 << 30 , U[i] = -1 << 30;
    for (i = 1 ; i <= m ; ++ i) {
        for (j = 1 ; j <= n ; ++ j) {
            if (s[j][i] == 'X') {
                D[i] = min(D[i] , j);
                U[i] = max(U[i] , j);
            }
        }
        bool flag = 0;
        for (j = D[i] ; j <= U[i] ; ++ j)
            if (s[j][i] != 'X')
                flag = 1;
        if (flag) {
            puts("-1");
            return 0;
        }
        if (D[i] <= U[i])
            X = min(X , U[i] - D[i] + 1);
    }
    for (i = 2 ; i <= m ; ++ i) {
        if (D[i] != 1 << 30 && D[i - 1] != 1 << 30) {
            int l = max(D[i] , D[i - 1]);
            int r = min(U[i] , U[i - 1]);
            X = min(X , r - l + 1);
        }
    }
    if (X < 1 || Y < 1) {
        puts("-1");
        return 0;
    }
    //cout << X << ' ' << Y << endl;

    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] == 'X')
                break;
        if (j <= m)
            break;
    }
    if (i > n) {
        puts("-1");
        return 0;
    }
    sx = i , sy = j;
    for (i = 1 ; i <= X ; ++ i)
        for (j = 1 ; j <= Y ; ++ j)
            if (i == X || j == Y)
                check(i , j);
    //cout << "hehe" <<endl;
    if (ans == 1 << 30)
        ans = -1;
    cout << ans << endl;
    return 0;
}