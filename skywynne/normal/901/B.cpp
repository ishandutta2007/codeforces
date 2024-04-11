#include<bits/stdc++.h>
using namespace std;
const int MXN = 160;
int n;
struct Polynomial
{
    int deg = 1;
    long double C[MXN];
    void operator %= (Polynomial &Z)
    {
        for (int i = deg; i >= Z.deg; i--)
            for (int j = Z.deg; j >= 0; j--)
                C[i - j] -= C[i] / Z.C[Z.deg] * Z.C[Z.deg - j];
        deg = Z.deg - 1;
    }
};
bool Solve(Polynomial X, Polynomial Y)
{
    Polynomial Z;
    for (int i = 1; i <= n; i++)
    {
        X %= Y;
        if (X.C[X.deg] < 1e-8 && X.C[X.deg] > -1e-8)
            return (0);
        Z = X, X = Y, Y = Z;
    }
    return (1);
}
int main()
{
    Polynomial X, Y;
    scanf("%d", &n);
    srand(time(0));
    while (1)
    {
        for (int i = 0; i < n; i++)
            X.C[i] = rand() % 3 - 1;
        for (int i = 0; i < n - 1; i++)
            Y.C[i] = rand() % 3 - 1;
        X.C[n] = Y.C[n - 1] = 1;
        X.deg = n;
        Y.deg = n - 1;
        if (Solve(X, Y) == 1)
        {
            printf("%d\n", n);
            for (int i = 0; i <= n; i++)
                printf("%d ", (int)X.C[i]);
            printf("\n%d\n", n - 1);
            for (int i = 0; i < n; i++)
                printf("%d ", (int)Y.C[i]);
            return (0);
        }
    }
}