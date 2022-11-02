// ItnoE
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q;
char A[N], T[N];
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%s", &n, A);
        for (int i = 0; i < n; i ++)
            A[i] -= '0';
        int l = 0, r = 9;
        while (l < 9)
        {
            int Mx = 0, F = 0;
            for (int i = 0; i < n; i ++)
                if (A[i] <= l + 1)
                    if (A[i] < Mx)
                        F = 1;
                    else
                        Mx = A[i];
            if (F) break;
            l ++;
        }
        while (r > 0)
        {
            int Mx = 0, F = 0;
            for (int i = 0; i < n; i ++)
                if (A[i] >= r - 1)
                    if (A[i] < Mx)
                        F = 1;
                    else
                        Mx = A[i];
            if (F) break;
            r --;
        }
        if (r - l > 2)
            {printf("-\n"); continue;}
        else if (r - l < 2)
            for (int i = 0; i < n; i ++)
                T[i] = (A[i] >= r) + '1';
        else
        {
            int le = -1, ri = n;
            for (int i = 0; i < n; i ++)
                if (A[i] <= l)
                    le = i;
            for (int i = n - 1; ~ i; i --)
                if (A[i] >= r)
                    ri = i;
            for (; ri < n; ri ++)
                if (A[ri] == r - 1)
                    break;
            for (; ~ le; le --)
                if (A[le] == l + 1)
                    break;
            if (ri <= le)
                {printf("-\n"); continue;}
            for (int i = 0; i < n; i ++)
                T[i] = '1' + (A[i] >= r || (A[i] == r - 1 && i < ri));
        }
        T[n] = 0;
        printf("%s\n", T);
    }
    return 0;
}