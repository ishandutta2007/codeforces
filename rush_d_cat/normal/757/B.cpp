#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int cnt[100007], n;
int a[100007];
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                if(j*j == a[i]) cnt[j]++;
                else cnt[j]++, cnt[a[i]/j]++;
            }
        }
    }
    int res = 1;
    for(int i=2;i<=100000;i++)
    {
        res = max(res, cnt[i]);
    }
    if(n == 1)
    {
        res = 1;
    }
    cout << res << endl;
}