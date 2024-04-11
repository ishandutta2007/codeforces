#include<bits/stdc++.h>
using namespace std;
const int N = 2019, MXL = 604, BS = 16;
int q, P[N];
long long A[MXL];
char S[MXL];
bitset < N > T, R, B[N], G[N];
int main()
{
    scanf("%d", &q);
    long long tbs = 1;
    for (int i = 1; i <= BS; i++)
        tbs *= 10;
    for (int id = 1; id <= q; id ++)
    {
        scanf("%s", &S);
        int len = strlen(S);
        reverse(S, S + len);
        memset(A, 0, sizeof(A));
        for (int i = 0; i < len; i += BS)
            for (int j = min(i + BS, len) - 1; j >= i; j--)
                A[i / BS] = A[i / BS] * 10 + (S[j] - '0');
        memset(S, 0, sizeof(S));
        len = (len - 1) / BS;
        for (int i = 0; i < N; i++)
        {
            B[id][i] = A[0] & 1;
            for (int j = len; j >= 0; j --)
            {
                if ((A[j] & 1) && j > 0)
                    A[j - 1] += tbs;
                A[j] >>= 1;
            }
        }
        T = B[id]; R = 0;
        for (int i = N - 1; ~i; i--)
            if (T[i] && P[i])
                T ^= B[P[i]], R ^= G[P[i]];
        if (T.count())
            printf("0\n");
        else
        {
            printf("%d", R.count());
            for (int i = 1; i < id; i++)
                if (R[i]) printf(" %d", i - 1);
            printf("\n");
        }
        G[id][id] = 1;
        for (int i = N - 1; ~i; i--)
            if (B[id][i])
            {
                if (P[i])
                    B[id] ^= B[P[i]], G[id] ^= G[P[i]];
                else
                {
                    P[i] = id;
                    break;
                }
            }
    }
    return (0);
}