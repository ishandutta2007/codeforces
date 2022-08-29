#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MAXN 105
using namespace std;
int data[MAXN];
int n;int tot=0;
int size[MAXN];
int main()
{
    scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&data[i]);
    sort(data+1,data+1+n);
    for(int i=1;i<=n;i++)
    {
            bool f=0;
            for(int j=1;j<=tot;j++)
            if(size[j]<=data[i])
            {
                                size[j]++;
                                f=1;
                                break;
                                }
            if(!f)size[++tot]=1;
            }
    printf("%d\n",tot);
    return 0;
}