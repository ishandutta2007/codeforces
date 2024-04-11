#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
using namespace std;
int n,k;
int a[MAXN];
int bit[MAXN+1];
bool used[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    bool f=true;
    int res=INF;
    memset(bit,0,sizeof(bit));
    memset(used,false,sizeof(used));
    int last=1;
    for(int i=0;i<k;i++)
    {
        res=min(res,a[i]);
        used[a[i]]=true;
        while(used[last]) last++;
        add(a[i],1);
        if(last<a[i]&&sum(a[i]-1)-sum(last-1)!=0) f=false;
    }
    if(!f) {printf("-1\n"); return 0;}
    for(int i=0;i<k;i++)
        printf("%d ",a[i]);
    f=false;
    used[n+1]=true;
    add(n+1,1);
    for(int i=1;i<=n+1;i++)
    {
        if(used[i]&&sum(i)!=i)
        {
            int t=i-1;
            while(!used[t]&&t>0)
            {
                printf("%d ",t);
                used[t]=true;
                add(t,1);
                t--;
            }
        }
    }
    return 0;
}