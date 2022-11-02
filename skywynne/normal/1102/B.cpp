#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, k, Mx, A[N], C[N], M[N];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1, a; i <= n; i++)
    {
        scanf("%d", &a);
        C[i] = ++ A[a];
        M[C[i]] ++;
        Mx = max(Mx, C[i]);
        if (C[i] > k)
            return !printf("NO");
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
    {
        if (M[C[i]] > 1 && Mx < k)
            M[C[i]] --, C[i] = ++ Mx;
        printf("%d ", C[i]);
    }
    return (0);
}