#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int m;
pair<int,int> b[MAXN];
int a[MAXN],ans[MAXN];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i].first);
        b[i].second=i;
    }
    sort(a+1,a+m+1,cmp);
    sort(b+1,b+m+1);
    for(int i=1;i<=m;i++)
        ans[b[i].second]=a[i];
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    return 0;
}