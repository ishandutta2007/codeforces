#include <iostream>
using namespace std;
int n, k, x;
int odd = 0;
int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &x);
        if (x % 2) odd ++;
    }

    if (n == k)
    {
        if (odd % 2)
        {
            printf("Stannis\n"); 
        } else {
            printf("Daenerys\n");
        }
        return 0;
    }

    if (n % 2 && k % 2)
    {
        int cnt = (k + 1) + ( n - (k+1) ) / 2;
        if (odd < cnt)
        {
            printf("Daenerys\n");
        } else {
            printf("Stannis\n");
        }
    }

    if (n % 2 && k % 2 == 0)
    {
        int x1 = (n - k + 1) / 2 ;
        int x2 = n - (n - k + 1) / 2;
        //printf("%d %d\n", x1, x2);

        if (odd < (n - k + 1) / 2 || odd > n - (n - k + 1) / 2)
        {
            printf("Daenerys\n");
        } else {
            printf("Stannis\n");
        }
    }

    if (n % 2 == 0 && k % 2)
    {
        int cnt = 1 + ( n - (k+1) ) / 2;

        if (odd < cnt)
        {
            printf("Daenerys\n");
        } else {
            printf("Stannis\n");
        }
    }

    if (n % 2 == 0 && k % 2 == 0)
    {
        printf("Daenerys\n");
    }
  
}