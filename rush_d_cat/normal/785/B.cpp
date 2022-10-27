#include <iostream>
#include <cstring>
using namespace std;
int n, m, l, r;
int max1, min1 = 1000000000+7, max2, min2=1000000000+7, ans = 0;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d", &l, &r);
        max1 = max(l, max1);
        min1 = min(min1, r);
    }
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &l, &r);
        max2 = max(l, max2);
        min2 = min(min2, r);
    }
    ans = max(ans, max2 - min1);
    ans = max(ans, max1 - min2);
    cout << ans << endl;
}