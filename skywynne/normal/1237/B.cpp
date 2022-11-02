// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 74;
int n, q, M[N], P[N], A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0, a; i < n; i ++)
        scanf("%d", &a), P[a] = i;
    for (int i = 0, a; i < n; i ++)
        scanf("%d", &a), A[P[a]] = i;
    for (int i = 0; i < n; i ++)
    {
        M[i] = max(M[i], A[i]);
        M[i + 1] = M[i];
    }
    int cnt = 0;
    for (int i = 1; i < n; i ++)
        if (M[i] > A[i])
            cnt ++;
    printf("%d\n", cnt);
    return 0;
}