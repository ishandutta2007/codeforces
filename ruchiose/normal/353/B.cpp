#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, C[100], A[220], T[100], S;

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 10, 99) C[i] = 0;
    fortodo(i, 1, N * 2)
        {
            scanf("%d", &A[i]);
            C[A[i]]++;
        }
    int p = 0;
    fortodo(i, 10, 99)
        p += min(2, C[i]);
    S = 2;
    fortodo(i, 10, 99)
        if (C[i] >= 2)
            T[i] = 3;
        else
            if (C[i])
                T[i] = (S ^= 3);
    printf("%d\n", (p / 2) * (p - (p / 2)));
    int slack0 = N - (p - (p / 2));
    fortodo(i, 1, N * 2)
        {
            if ((C[A[i]]--) > 2)
                printf("%d", (--slack0 >= 0) ? 1 : 2);
            else
                if (T[A[i]] & 1)
                    {
                        printf("1");
                        T[A[i]] &= ~1;
                    }
                else
                    printf("2");
            printf("%s", (i == N * 2) ? "\n" : " ");
        }
}