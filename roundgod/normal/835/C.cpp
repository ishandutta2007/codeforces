#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
int n,q,c;
int bit[11][MAXN+1][MAXN+1];
int sum(int k,int i,int j)
{
    int t,s=0;
    while(i>0)
    {
        t=j;
        while(t>0)
        {
            s+=bit[k][i][t];
            t-=t&-t;
        }
        i-=i&-i;
    }
    return s;
}
void add(int k,int i,int j,int x)
{
    int t;
    while(i<=MAXN)
    {
        t=j;
        while(t<=MAXN)
        {
            bit[k][i][t]+=x;
            t+=t&-t;
        }
        i+=i&-i;
    }
}
int main()
{
    scanf("%d %d %d",&n,&q,&c);
    memset(bit,0,sizeof(bit));
    for(int i=0;i<n;i++)
    {
        int x,y,s;
        scanf("%d %d %d",&x,&y,&s);
        add(s,x,y,1);
    }
    for(int i=0;i<q;i++)
    {
        int t,x1,y1,x2,y2;
        scanf("%d %d %d %d %d",&t,&x1,&y1,&x2,&y2);
        int s=0;
        for(int j=0;j<c+1;j++)
            s+=(sum(j,x2,y2)-sum(j,x1-1,y2)-sum(j,x2,y1-1)+sum(j,x1-1,y1-1))*((j+t)%(c+1));
        printf("%d\n",s);
    }
    return 0;
}