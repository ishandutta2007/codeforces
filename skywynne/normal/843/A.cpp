#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 10;
int n, r, t, A[MXN], B[MXN], C[MXN];
vector < int > V[MXN];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        B[i] = A[i];
    }
    sort(B, B + n);
    for (int i = 0; i < n; i++)
        C[i] = lower_bound(B, B + n, A[i]) - B;
    for (int i = 0; i < n; i++)
    {
        r = i;
        if (B[r] == 1e9 + 10)
            continue;
        V[t].push_back(r + 1);
        while (A[C[r]] != A[i])
        {
            r = C[r];
            B[r] = 1e9 + 10;
            V[t].push_back(r + 1);
        }
        t ++;
    }
    printf("%d\n", t);
    for (int i = 0; i < t; i++)
    {
        printf("%d", (int)V[i].size());
        for (int j = 0; j < (int)V[i].size(); j++)
            printf("% d", V[i][j]);
        printf("\n");
    }
    return (0);
}