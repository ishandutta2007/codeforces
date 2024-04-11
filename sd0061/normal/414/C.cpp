#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
#define N 1200000
int n , a[N] , m;
int b[21][N];
LL sum[21][N] , cnt[21][N];
LL Q[21] , W[21];
void work()
{
    int i , j , k;
    scanf("%d",&n);
    for (i = 0 ; i < 1 << n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 0 ; i < 1 << n ; ++ i) {
        b[0][i] = a[i];
    }
    for (j = 1 ; j <= n ; ++ j) {
        int L = 1 << j - 1;
        for (k = 0 ; k < 1 << n - j ; ++ k) { // zushu
            // [k << j , k + 1 << j)
            int A = k << 1 , B = k << 1 | 1;
            int X = A << j - 1 , Y = B << j - 1;
            int x = 0 , y = 0;
            int p = 0;
            cnt[j][k] = cnt[j - 1][A] + cnt[j - 1][B];
            while (x < L && y < L) {
                if (b[j - 1][X + x] <= b[j - 1][Y + y])
                    b[j][(k << j) + p] = b[j - 1][X + x] , ++ p , ++ x;
                else
                    b[j][(k << j) + p] = b[j - 1][Y + y] , ++ p , ++ y , cnt[j][k] += L - x;
            }
            while (x < L)
                b[j][(k << j) + p] = b[j - 1][X + x] , ++ p , ++ x;
            while (y < L)
                b[j][(k << j) + p] = b[j - 1][Y + y] , ++ p , ++ y , cnt[j][k] += L - x;
            Q[j] += cnt[j][k];
        }
    }
    reverse(a , a + (1 << n));
    for (i = 0 ; i < 1 << n ; ++ i) {
        b[0][i] = a[i];
    }
    for (j = 1 ; j <= n ; ++ j) {
        int L = 1 << j - 1;
        for (k = 0 ; k < 1 << n - j ; ++ k) { // zushu
            // [k << j , k + 1 << j)
            int A = k << 1 , B = k << 1 | 1;
            int X = A << j - 1 , Y = B << j - 1;
            int x = 0 , y = 0;
            int p = 0;
            sum[j][k] = sum[j - 1][A] + sum[j - 1][B];
            while (x < L && y < L) {
                if (b[j - 1][X + x] <= b[j - 1][Y + y])
                    b[j][(k << j) + p] = b[j - 1][X + x] , ++ p , ++ x;
                else
                    b[j][(k << j) + p] = b[j - 1][Y + y] , ++ p , ++ y , sum[j][k] += L - x;
            }
            while (x < L)
                b[j][(k << j) + p] = b[j - 1][X + x] , ++ p , ++ x;
            while (y < L)
                b[j][(k << j) + p] = b[j - 1][Y + y] , ++ p , ++ y , sum[j][k] += L - x;
            W[j] += sum[j][k];
        }
    }
    scanf("%d",&m);
    LL res = cnt[n][0];
    while (m --) {
        int x;
        scanf("%d",&x);
        res -= Q[x] , res += W[x];
        for (i = 0 ; i < x ; ++ i)
            swap(Q[i] , W[i]);
        for (i = x + 1 ; i <= n ; ++ i)
            Q[i] -= Q[x] - W[x] , W[i] -= W[x] - Q[x];
        swap(Q[x] , W[x]);
        printf("%I64d\n" , res);
    }

}


int main()
{
    work();
    return 0;
}