#include <iostream>
using namespace std;
const int NICO = 9000000 + 10;
double dp[NICO];
int a[NICO], n;
int main()
{
    
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int k = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i] > a[j]) k++;
        }
    }
    dp[0] = 0, dp[1] = 1;
    for(int i=2;i<=k;i++)
    {
        dp[i] = dp[i-2] + 4;
    }
    printf("%.6f\n", dp[k]);
}