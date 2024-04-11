#include <iostream>
#include <cstdio>
#include <fstream>

#define mx 200

using namespace std;

long long res [500010];
long long a [500010];
struct ver{long x, id, next;};
ver sm [1000010];
long x, n, i, p, num, j, a1, b1, k;
long long curp [2 * mx][2 * mx];  
long ind [2 * mx];
long en [300010];
long beg [300010];

void add(long a, long b, long c)
{
     num++;
     sm[num].x = b;
     sm[num].id = c;
     sm[num].next = 0;
     if (en[a] != 0) sm[en[a]].next = num;
     if (beg[a] == 0) beg[a] = num;     
     en[a] = num;
}

int main()
{
    scanf("%ld", &n);
    for (i = 0; i < 300010; i++)
    {
        beg[i] = 0;
        en[i] = 0;
    } 
    if (n < mx) 
       x = n;
    else 
       x = mx;  
    for (i = 0; i < 2 * mx; i++)
    {
        ind[i] = 1;
        for (j = 0; j++; j < 2 * mx) curp[i][j] = 0;
    }    
    for (i = 1; i <= n; i++) scanf("%ld", &a[i]);
    scanf("%ld", &p);
    for (i = 1; i <= p; i++)
    {
        scanf("%ld%ld", &a1, &b1);
        add(a1, b1, i);
    }
    for (i = n; i > 0; i--)
    {
        for (j = 1; j <= x; j++)
        {
            if (ind[j] == j) ind[j] = 1; else ind[j]++;
            curp[j][ind[j]] += a[i];
        }
        for (j = beg[i]; j > 0; )
        {
            if (sm[j].x > x)
            {
               res[sm[j].id] = 0;
               for (k = i; k <= n; ){
                   res[sm[j].id] += a[k];
                   k += sm[j].x;
               }
            }
            else res[sm[j].id] = curp[sm[j].x][ind[sm[j].x]];
            j = sm[j].next;
        }
    }
    for (i = 1; i <= p; i++)
    printf("%I64d \n", res[i]);
    //cin >> n;    
    return 0;
}