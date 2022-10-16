#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,ans;
int v[1005];
char t[1005];
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s",t+1);
        for (j=1;t[j];j++)
            v[i]|=1<<(t[j]-'a');
    }
    sort(v+1,v+n+1);
    for (i=1;i<=n;i++)
        if (v[i]!=v[i-1])
            ans++;
    printf("%d\n",ans);
    return 0;
}