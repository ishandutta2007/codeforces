#include<bits/stdc++.h>
using namespace std;
int v=2;
int edge[1000000][2];
int tot=0;
void build_path(int o,int len)
{
    int last=o;
    for (int i=0;i<len;i++)
    {
        edge[tot][0]=last,edge[tot][1]=v;
        last=v;
        v++,tot++;
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int center=1;
    int num=(n-1)/k;
    int extra=(n-1)%k;
    for (int i=0;i<extra;i++)
        build_path(center,num+1);
    for (int i=0;i<k;i++)
        build_path(center,num);
    int ret=0;
    if (extra==0)
        ret=num*2;
    else if (extra==1)
        ret=num*2+1;
    else
        ret=num*2+2;
    printf("%d\n",ret);
    for (int i=0;i+1<n;i++)
        printf("%d %d\n",edge[i][0],edge[i][1]);
}