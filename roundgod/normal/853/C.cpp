#include<bits/stdc++.h>
#define MAXN 200055
#define MAXQ 200055
using namespace std;
typedef long long lx;
int bit[MAXN+1],n,q;
struct rect
{
    int x,y,st,num;
}a[4*MAXQ];
int ord[MAXQ][4],lu[MAXQ],ru[MAXQ],ll[MAXQ],rl[MAXQ];
int p[MAXN];
bool cmp(rect i,rect j)
{
    if(i.x!=j.x) return i.x<j.x;
    else return i.y<j.y;
}
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
lx C(int x)
{
    lx s=(lx)x;
    s=s*(s-1)/2;
    return s;
}
int main()
{
    scanf("%d %d",&n,&q);
    int w;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w);
        p[w]=i;
    }
    int l,d,r,u;
    for(int i=0;i<q;i++)
    {
        scanf("%d %d %d %d",&l,&d,&r,&u);
        ord[i][0]=l-1;
        ord[i][1]=n-r;
        ord[i][2]=d-1;
        ord[i][3]=n-u;
        a[4*i].st=1;
        a[4*i+1].st=2;
        a[4*i+2].st=3;
        a[4*i+3].st=4;
        a[4*i].num=a[4*i+1].num=a[4*i+2].num=a[4*i+3].num=i;
        a[4*i].x=d-1;
        a[4*i].y=l-1;
        a[4*i+1].x=d-1;
        a[4*i+1].y=r;
        a[4*i+2].x=u;
        a[4*i+2].y=l-1;
        a[4*i+3].x=u;
        a[4*i+3].y=r;
    }
    sort(a,a+4*q,cmp);
    memset(bit,0,sizeof(bit));
    int k=0;
    for(int i=0;i<=n;i++)
    {
        if(i!=0) add(p[i],1);
        while(a[k].x==i&&k<4*q)
        {
            if(a[k].st==1) lu[a[k].num]=sum(a[k].y);
            if(a[k].st==2) ru[a[k].num]=ord[a[k].num][2]-sum(a[k].y);
            if(a[k].st==3) ll[a[k].num]=ord[a[k].num][0]-sum(a[k].y);
            if(a[k].st==4) rl[a[k].num]=ord[a[k].num][1]+ord[a[k].num][3]+sum(a[k].y)-n;
            k++;
        }
    }
    for(int i=0;i<q;i++)
        printf("%I64d\n",C(n)-C(ord[i][0])-C(ord[i][1])-C(ord[i][2])-C(ord[i][3])+C(lu[i])+C(ru[i])+C(ll[i])+C(rl[i]));
    return 0;
}