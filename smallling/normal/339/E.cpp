#include<cstdio>
#include<algorithm>

using namespace std;

int ans1[5],ans2[5],sum,n,a[1010];

int dfs(int x)
{
    int l=0,r=0;
    if(x>3)
    {
        for(int i=1;i<=n;i++)
            if(a[i]^i)return 0;
        return 1;
    }
    for(int i=1;i<=n;i++)
        if(a[i]^i)
        {
            l=i;
            break;
        }
    if(!l)return 1;
    for(int i=1;i<=n;i++)
        if(a[i]==l)
        {
            r=i;
            break;
        }
    reverse(a+l,a+r+1);
    if(dfs(x+1))
    {
        ans1[++sum]=l;
        ans2[sum]=r;
        return 1;
    }
    reverse(a+l,a+r+1);
    for(int i=n;i;i--)
        if(a[i]^i)
        {
            r=i;
            break;
        }
    for(int i=1;i<=n;i++)
        if(a[i]==r)
        {
            l=i;
            break;
        }
    reverse(a+l,a+r+1);
    if(dfs(x+1))
    {
        ans1[++sum]=l;
        ans2[sum]=r;
        return 1;
    }
    reverse(a+l,a+r+1);
    return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1);
    if(sum)
    {
        printf("%d\n",sum);
        for(int i=1;i<=sum;i++)
            printf("%d %d\n",ans1[i],ans2[i]);
    }
    else 
    {
        swap(a[5],a[6]);
        dfs(1);
        if(sum)
        {
            printf("%d\n",sum+1);
            for(int i=sum;i;i--)
                printf("%d %d\n",ans1[i],ans2[i]);
            puts("5 6");
        }
        else puts("2"),puts("1 2"),puts("1 2");
    }
}