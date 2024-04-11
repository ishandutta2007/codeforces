#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

int N, i, j, k, A[101];
bool Avai[101];
int Ans, Cnt;

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    sort(A + 1, A + N + 1);
    fortodo(i, 1, N) Avai[i] = true;
    Ans = 0;
    fortodo(i, 1, N)
        if (Avai[i])
            {
                Ans++;
                Cnt = 1;
                Avai[i] = false;
                do
                    {
                        fortodo(j, i + 1, N)
                            if ((Avai[j]) && (A[j] >= Cnt))
                                {
                                    Avai[j] = false;
                                    Cnt++;
                                    continue;
                                }
                    }
                while (0);
            }
    printf("%d\n", Ans);
};