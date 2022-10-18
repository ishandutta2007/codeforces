#include<bits/stdc++.h>
using namespace std;
int a[212345];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
         int n, p, k;
         scanf("%d %d %d", &n, &p, &k);
         for(int i = 0; i < n; i++) scanf("%d", &a[i]);
         sort(a, a + n);
         int sum1 = 0;
         int sum2 = 0;
         int ans = 0;
         for(int i = 0; i < n; i++)
         {
             int x = a[i];
             if(i % 2 == 0) 
             {
                 if (sum1 + x <= p) 
                 {
                     sum1 += x;
                     ans ++;
                 }
             }
             else 
             {
                if(sum2 + x <= p)
                {
                    sum2 += x;
                    ans ++;
                }
             }
         }
         printf("%d\n", ans);
    }
    return 0;
}