// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q;
char A[N];
int main()
{
    scanf("%s", &A);
    n = strlen(A);
    int Mn = 'z' + 1;
    for (int i = 0; i < n; i ++)
    {
        if (Mn < A[i])
            printf("Ann\n");
        else
            printf("Mike\n");
        Mn = min(Mn, (int)A[i]);
    }
    return 0;
}