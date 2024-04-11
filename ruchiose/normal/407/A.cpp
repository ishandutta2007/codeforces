// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
#define mp make_pair
using namespace std;

int Int_Sqrt(int x)
{
    double r = sqrt(x);
    if (abs(r - int(r)) < 1e-7)
        return int(r);
    else
        return -1;
}

int Euclid(int a, int b)
{
    return (b) ? Euclid(b, a % b) : a;
}

int A, B, Ax, Ay, E, AL, BR;

int main()
{
    scanf("%d%d", &A, &B);
    fortodo(Ax, 1, A - 1)
        {
            Ay = Int_Sqrt(A * A - Ax * Ax);
            if (Ay == -1) continue;
            E = Euclid(Ax, Ay);
            AL = A / E;
            if ((B % AL == 0) && (Ax != ((Ay / E) * (B / AL))))
                {
                    BR = B / AL;
                    printf("YES\n");
                    printf("0 0\n");
                    printf("%d %d\n", Ax, Ay);
                    printf("%d %d\n", (Ay / E) * BR, -(Ax / E) * BR);
                    return 0;
                }
        }
    printf("NO\n");
    return 0;
}