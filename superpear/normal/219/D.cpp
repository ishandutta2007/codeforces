#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>

#define maxlongint 2147483647

using namespace std;

const int maxn=300000;

struct ljb
{
    ljb *next;
    int dest,flag;
};

ljb *head[maxn],*tail[maxn],*p;
int hash[maxn],size[maxn],fan[maxn],ans[maxn];
int n,xa,ya,minc;

void mpush(int x,int y,int z)
{
    ljb *p;
    p=new ljb;
    p->dest=y;
    p->flag=z;
    p->next=0;
    tail[x]->next=p;
    tail[x]=p;
}

void mcalc(int s)
{
    ljb *p;
    hash[s]=1;
    size[s]=1;
    p=head[s]->next;
    while (p!=0)
    {
        if (hash[p->dest]==0)
        {
            mcalc(p->dest);
            size[s]+=size[p->dest];
            fan[s]+=fan[p->dest]+p->flag;
        }
        p=p->next;
    }
}

void mdoit(int s,int nowans)
{
    int c1;
    ljb *p;
    hash[s]=1;
    ans[s]=nowans+fan[s];
    p=head[s]->next;
    while (p!=0)
    {
        if (hash[p->dest]==0)
        {
            c1=fan[s]-fan[p->dest]-p->flag;
            c1=c1+1-p->flag+nowans;
            mdoit(p->dest,c1);
        }
        p=p->next;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        p=new ljb;
        p->dest=0;
        p->next=0;
        p->flag=0;
        head[i]=p;
        tail[i]=p;
    }
    for (int i=1;i<n;i++)
    {
        scanf("%d %d",&xa,&ya);
        mpush(xa,ya,0);
        mpush(ya,xa,1);
    }
    memset(size,0,sizeof(size));
    memset(fan,0,sizeof(fan));
    memset(hash,0,sizeof(hash));
    mcalc(1);
    memset(ans,0,sizeof(ans));
    memset(hash,0,sizeof(hash));
    mdoit(1,0);
    minc=maxlongint;
    for (int i=1;i<=n;i++)
        if (ans[i]<minc) minc=ans[i];
    printf("%d\n",minc);
    int flagc=1;
    for (int i=1;i<=n;i++)
        if (ans[i]==minc)
        {
            if (flagc==0) printf(" ");
            printf("%d",i);
            flagc=0;
        }
    printf("\n");
    return 0;
}