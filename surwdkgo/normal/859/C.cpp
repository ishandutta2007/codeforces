#include <stdio.h>

int main()
{
    int n, sum = 0;
    int inp[55];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &inp[i]);
    }
    int best = 0;
    for (int i= n-1; i>= 0; i--)
    {
        int nBest = best;
        if (inp[i] + sum - best > nBest) nBest = inp[i] + sum - best;
        best = nBest;
        sum += inp[i];
    }
    printf ("%d %d\n", sum - best, best);
    return 0;
}