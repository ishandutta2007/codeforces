#include<bits/stdc++.h>
#define MAXN 800001
using namespace std;
int n,x;
bool used[MAXN];
int main()
{
    scanf("%d %d",&n,&x);
    if(n==2&&x==0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    memset(used,false,sizeof(used));
    int ans=0;
    if(n==1)
    {
        printf("%d\n",x);
        return 0;
    }
    if(n==2)
    {
        printf("0 %d\n",x);
        return 0;
    }
    for(int i=1;i<=n-2;i++)
    {
        used[i]=true;
        ans^=i;
    }
    if(ans==x)
    {
        used[1]=false;
        used[262144]=true;
        used[262145]=true;
        used[0]=true;
    }
    else
    {
        used[262144+ans]=true;
        used[262144+x]=true;
    }
    for(int i=0;i<MAXN;i++)
        if(used[i]) printf("%d ",i);
    return 0;
}