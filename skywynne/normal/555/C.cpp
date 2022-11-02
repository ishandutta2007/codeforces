#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n, q, x, y;
char c;
map < int , int > M;
pair < int , int > P, T;
set < pair < int , int > > S;
int main()
{
    scanf("%d %d", &n, &q);
    T.f = 0;
    T.s = 2;
    S.insert(T);
    T.f = n + 1;
    T.s = 1;
    S.insert(T);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d %d %c", &x, &y, &c);
        if (M.count(x) != 0)
        {
            printf("0\n");
            continue;
        }
        T.f = x;
        T.s = 0;
        if (c == 'L')
        {
            P = *(--S.lower_bound(T));
            if (P.s == 2)
            {
                M[x] = x - P.f;
            }
            else
            {
                M[x] = x - P.f + M[P.f];
            }
            P.f = x;
            P.s = 1;
            S.insert(P);
        }
        else
        {
            P = *S.upper_bound(T);
            if (P.s == 1)
            {
                M[x] = P.f - x;
            }
            else
            {
                M[x] = M[P.f] + P.f - x;
            }
            P.f = x;
            P.s = 2;
            S.insert(P);
        }
        printf("%d\n", M[x]);
    }
    return (0);
}