#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int i,j,k,l,n,an,sum,tot,s,m;
const int N=5100;
bool ff[N];
int main()
{
    scanf("%d%d",&n,&m);
    n--;
    for (int i=1;i<=m;i++)
    {
        int t,x,y;
        scanf("%d",&t);
        if (t==1) {scanf("%d%d",&x,&y);ff[x]=ff[y]=true;}
        else 
        scanf("%d",&x);
        ff[x]=true;
    }
    s=0;
    for (int i=1;i<=n;i++) if (!ff[i]) s++;
    int i;
    for (i=1;i<=n;i++)if (!ff[i]){an++;ff[i+1]=true;}
    printf("%d %d\n",an,s);
    return 0;
}