// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q;
char A[N];
int main()
{
    scanf("%d%s", &n, &A);
    int nn = 0, zz = 0;
    for (int i = 0; i < n; i ++)
        nn += (A[i] == 'n'), zz += (A[i] == 'z');
    for (int i = 0; i < nn; i ++)
        printf("1 ");
    for (int i = 0; i < zz; i ++)
        printf("0 ");
    return 0;
}