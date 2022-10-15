#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXLOGN 20
#define INF 1000000000
using namespace std;
int n,q,bit[MAXN+1];
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
int bisearch(int v)
{
    int sum=0,pos=0;
    for(int i=MAXLOGN;i>=0;i--)
    {
        if(pos+(1<<i)<=n&&sum+bit[pos+(1<<i)]<v)
        {
            sum+=bit[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos+1;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add(x,1);
    }
    for(int i=1;i<=q;i++)
    {
        int x;
        scanf("%d",&x);
        if(x>0)
        {
            add(x,1);
        }
        else
        {
            int v=bisearch(-x);
            add(v,-1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(sum(i))
        {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("0");
}