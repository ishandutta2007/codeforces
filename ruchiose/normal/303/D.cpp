#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, P, X;

bool Isp(int x)
{
    for (int a = 2; a * a <= x; a++)
        if (x % a == 0)
            return false;
    return true;
}

i64 qipow(i64 b, i64 t, i64 p)
{
    i64 a = 1;
    for (; t; t >>= 1)
        {
            if (t & 1) a = (a * b) % p;
            b = (b * b) % p; 
        }
    return a;
}

int Dv[30];

void Decompose(int x)
{
    Dv[0] = 0;
    int i;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            {
                Dv[++Dv[0]] = i;
                while (x % i == 0) x /= i;
            }
    if (x > 1) Dv[++Dv[0]] = x;
}

bool Isprimitive(int y)
{
    if (qipow(y, N, P) != 1) return false;
    int i;
    fortodo(i, 1, Dv[0])
        if (qipow(y, N / Dv[i], P) == 1)
            return false;
    return true;
}

int main()
{
    scanf("%d%d", &N, &X);
    P = N + 1;
    if (!Isp(P))
        {
            printf("-1\n");
            return 0;
        }
    int F = min(X - 2, P);
    int i;
    Decompose(N);
    fortodo(i, 1, F)
        if (Isprimitive((X - i) % P))
            {
                printf("%d\n", X - i);
                return 0;
            }
    printf("-1\n");
    return 0;
}