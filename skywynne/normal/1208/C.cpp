// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int q, n, A[N][N];
int main()
{
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n / 2; i ++)
        for (int j = 0; j < n / 2; j ++)
        {
            int ii = i * 2;
            int jj = j * 2;
            A[ii][jj] = cnt ++;
            A[ii][jj + 1] = cnt ++;
            A[ii + 1][jj] = cnt ++;
            A[ii + 1][jj + 1] = cnt ++;
        }
    for (int i = 0; i < n; i ++, printf("\n"))
        for (int j = 0; j < n; j ++)
            printf("%d ", A[i][j]);
    return 0;
}