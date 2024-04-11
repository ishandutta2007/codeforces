#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const double INF = 100000;
typedef long long ll;
int d[5002], a[5002];
int main()
{
    int n, i;cin>>n;
    for(i = 1; i <= n-1; i++)
    {
        printf("? %d %d\n", i, (i+1));
        fflush(stdout);
        scanf("%d", &a[i]);
    }
    printf("? %d %d\n", 1, 3);
    fflush(stdout);
    scanf("%d", &a[n]);
    d[1] = a[1];
    for(i = 2; i <= n-1; i++)
    {
        if(i%2) d[i] = d[i-1] + a[i];
        else d[i] = d[i-1] - a[i];
    }
    int x = (a[n] + d[2]) / 2;
    printf("! %d", x);

    for(i = 2; i <= n; i++)
    {
        if(i%2==0) printf(" %d", (-x + d[i-1]));
        else printf(" %d", (x - d[i-1]));
    }
    printf("\n");
    fflush(stdout);
}