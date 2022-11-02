// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector < int > A(n), P(n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &A[i]), P[i] = i;
    sort(P.begin(), P.end(), [&](int i, int j){return (A[i] > A[j]);});
    int tot = 0;
    for (int i = 0; i < n; i ++)
        tot += A[P[i]] * i + 1;
    printf("%d\n", tot);
    for (int a : P)
        printf("%d ", a + 1);
    return 0;
}