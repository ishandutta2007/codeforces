// ItnoE
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, A[N], B[N];
char S[N];
int main()
{
    scanf("%d%s", &n, S);
    for (int i = 0; i < n; i ++)
        scanf("%d%d", &A[i], &B[i]);
    int Mx = 0;
    for (int t = 0; t < 100 * 100; t ++)
    {
        int Cnt = 0;
        for (int i = 0; i < n; i ++)
            Cnt += (S[i] - '0') == (t < B[i] || (t - B[i]) / A[i] % 2 == 1);
        Mx = max(Mx, Cnt);
    }
    return !printf("%d\n", Mx);
}