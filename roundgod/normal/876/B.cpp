#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m,k;
int a[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]%m]++;
    }
    for(int i=0;i<m;i++)
        if(cnt[i]>=k)
        {
            printf("Yes\n");
            int s=0;
            for(int j=0;j<n;j++)
            {
                if(a[j]%m==i)
                {
                    printf("%d ",a[j]);
                    s++;
                }
                if(s==k) return 0;
            }
        }
    printf("No\n");
    return 0;
}