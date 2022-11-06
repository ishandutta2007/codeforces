#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int K, N, i, j;
bool C[101][101];

int Cn3(int n)
{
    return ((n - 2) * (n - 1) * n) / 6;
}

int Cn2(int n)
{
    return ((n - 1) * n) / 2;
}

void Fill(int l, int r)
{
    int i, j;
    fortodo(i, l, r)
        fortodo(j, i + 1, r)
            C[i][j] = C[j][i] = true;
}

int main()
{
    cin >> K;
    fortodo(i, 1, 100)
        fortodo(j, 1, 100)
            C[i][j] = false;
    N = 0;
    for (i = 100; i >= 3; i--)
        if (Cn3(i) <= K)
            {
                K -= Cn3(i);
                Fill(1, i);
                N = i;
                break;
            }
    for (; i >= 2; i--)
        while (Cn2(i) <= K)
            {
                K -= Cn2(i);
                fortodo(j, 1, i)
                    C[N + 1][j] = C[j][N + 1] = true;
                N++;
            }
    printf("%d\n", N);
    fortodo(i, 1, N)
        {
            fortodo(j, 1, N)
                if (C[i][j])
                    printf("1");
                else
                    printf("0");
            printf("\n");
        }
}