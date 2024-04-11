#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define mk make_pair
using namespace std;
int i,j,k,l,n,m,sum,an,M,s;
const int N=4100;
int a[N],fa[N];
int anx[N],any[N],size[N];
int get(int x)
{
    if (x==fa[x]) return x;
    fa[x]=get(fa[x]);
    return fa[x];
}
int find(int x)
{
    for (int i=1;i<=n;i++)
    if (a[i]==x) return i;
    return 0;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=1;i<=n;i++)
    if (!fa[i])
    {
        //ff[i]=true;
        int x=i;
        int ss=0;
        while (true)
        {
            fa[x]=i;
            ss++;
            if (a[x]==i) break;
            x=a[x];
        }
        an+=ss-1;
    }
    if (an==m) {printf("0\n");return 0;}
    if (an>m)
    {
        s=0;
        while (true)
        {
        for (int i=1;i<=n;i++)
        if (a[i]!=i)
        {
            int x=a[i];
            int k=x;
            while (true)
            {
                k=min(k,x);
                if (a[x]==i) break;
                x=a[x];
            }
            anx[++s]=i,any[s]=k;
            swap(a[i],a[k]);
            an--;
            break;
        }
         if (an==m) break;
        }
        printf("%d\n",s);
        for (int i=1;i<=s;i++)
        printf("%d %d\n",min(any[i],anx[i]),max(anx[i],any[i]));
    }
    else
    {
        s=0;
        while (true)
        {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            if (get(a[i])!=get(a[j]))
            {
                fa[get(a[i])]=get(a[j]);
                swap(a[i],a[j]);
                anx[++s]=i,any[s]=j;
                an++;
                goto aaa;
                
            }
        }
        aaa:;
        if (an==m) break;
        }
        printf("%d\n",s);
        for (int i=1;i<=s;i++)
        printf("%d %d\n",min(any[i],anx[i]),max(anx[i],any[i]));
    }
    return 0;
}