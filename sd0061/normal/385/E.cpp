#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define N 100002
long long n , sx , sy , dx , dy , t;
struct Matrix
{
    int n , m ;
    long long a[6][6];
    Matrix() {memset(a , 0 , sizeof(a));}
    Matrix(int _n , int _m) {
        n = _n , m = _m , memset(a , 0 , sizeof(a));
    };
};
Matrix operator * (Matrix A , Matrix B)
{
    Matrix ans(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)
            for (int k = 0 ; k < B.m ; ++ k)
                ans.a[i][k] += A.a[i][j] * B.a[j][k] % n , ans.a[i][k] %= n;
    return ans;
}
void work()
{
    cin >> n >> sx >> sy >> dx >> dy >> t;
    dx += sx + sy , dy += sx + sy;
    -- sx , -- sy;
    while (dx < 0) dx += n;
    while (dy < 0) dy += n;
    Matrix I(1 , 6) , P(6 , 6);
    I.a[0][0] = sx , I.a[0][1] = sy , I.a[0][2] = dx , I.a[0][3] = dy , I.a[0][4] = 1 , I.a[0][5] = 1;

    P.a[0][0] = 1 , P.a[0][2] = 1 , P.a[0][3] = 1;
    P.a[1][1] = 1 , P.a[1][3] = 1 , P.a[1][2] = 1;
    P.a[2][0] = 1 , P.a[2][2] = 2 , P.a[2][3] = 1;
    P.a[3][1] = 1 , P.a[3][3] = 2 , P.a[3][2] = 1;
    P.a[4][2] = P.a[4][3] = P.a[4][4] = 1;
    P.a[5][4] = P.a[5][5] = 1 , P.a[5][2] = P.a[5][3] = 2;
    while (t)
    {
        if (t & 1)
            I = I * P;
        P = P * P , t >>= 1;
    }
    printf("%I64d %I64d\n" , I.a[0][0] + 1 , I.a[0][1] + 1);
}

int main()
{
    work();
    return 0;
}