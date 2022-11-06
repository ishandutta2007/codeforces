#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, Min, Max, i, j;
int Nowmin, Nowmax;

int main()
{
    scanf("%d%d%d%d", &N, &M, &Min, &Max);
    Nowmin = 0x3fffffff;
    Nowmax = 0;
    fortodo(i, 1, M)
        {
            scanf("%d", &j);
            Nowmin = min(Nowmin, j);
            Nowmax = max(Nowmax, j);
        }
    if ((Nowmin < Min) || (Nowmax > Max))
        printf("Incorrect\n");
    else
        {
            int Nessi = ((Nowmin != Min) ? 1 : 0) + ((Nowmax != Max) ? 1 : 0);
            if (N - M >= Nessi)
                printf("Correct\n");
            else
                printf("Incorrect\n");
        }
}