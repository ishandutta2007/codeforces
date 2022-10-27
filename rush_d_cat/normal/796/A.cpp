#include <iostream>
using namespace std;
int n, m, k;
int a[202];
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    int ans = 200;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i] == 0) continue;
        if(a[i] <= k)
        {
            ans = min(ans, abs(m-i));
        }
    }
    printf("%d\n", 10*ans);
}