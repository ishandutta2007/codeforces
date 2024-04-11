#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define L x*2
#define R L+1
int tree[1000000][4];
int vs[1000000][4];
int num[1000000][4];
void build(int x,int l,int r)
{
    if (l==r)
        for (int i=0;i<4;i++)
            tree[x][i]+=num[l][i];
    else
    {
        build(L,l,mid);
        build(R,mid+1,r);
        for (int i=0;i<4;i++)
            tree[x][i]=tree[L][i]+tree[R][i];
    }
}
int query(int x,int l,int r,int s,int e,int v)
{
    if (s>e)return 0;
    if (s>r || e<l)
        return 0;
    if (l>=s && r<=e)
        return tree[x][v];
    return query(L,l,mid,s,e,v)+query(R,mid+1,r,s,e,v);
}
int main()
{
    int n;
    int X,Y;
    scanf("%d%d%d",&n,&X,&Y);
    for (int i=1;i<=n;i++)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        vs[i][0]=min(x1,x2);
        num[vs[i][0]][0]++;
        vs[i][1]=max(x1,x2);
        num[vs[i][1]][1]++;
        vs[i][2]=min(y1,y2);
        num[vs[i][2]][2]++;
        vs[i][3]=max(y1,y2);
        num[vs[i][3]][3]++;
    }
    int UU,LL,RR,DD;
    scanf("%d%d%d%d",&LL,&RR,&UU,&DD);
    int tot=max(X,Y);
    build(1,1,tot);
    for (int i=1;i<=n;i++)
    {
        int UUU=query(1,1,tot,1,vs[i][3]-1,2);
        int DDD=query(1,1,tot,vs[i][2]+1,tot,3);
        int LLL=query(1,1,tot,1,vs[i][1]-1,0);
        int RRR=query(1,1,tot,vs[i][0]+1,tot,1);
        if (vs[i][0]==vs[i][1])
            UUU--,DDD--;
        else
            LLL--,RRR--;
        if (UU==UUU && RR==RRR && LL==LLL && DD==DDD)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
}