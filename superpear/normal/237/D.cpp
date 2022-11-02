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
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

struct ljb
{
    int dest;
    ljb *next;
};

pair<int,int> f[120000];
ljb *head[120000],*tail[120000],*p;
int hash[120000],fa[120000];
int n,o;

void mpush(int x,int y)
{
    ljb *p;
    p=new ljb;
    p->dest=y;p->next=0;
    tail[x]->next=p;tail[x]=p;
}

void dfs(int s)
{
    ljb *p;
    hash[s]=1;
    p=head[s]->next;
    while (p!=0)
    {
        if (hash[p->dest]==0)
        {
            ++o;
            f[o]=make_pair(s,p->dest);
            fa[p->dest]=o;
            dfs(p->dest);
        }
        p=p->next;
    }
}

int main()
{
    int x1,y1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        p=new ljb;
        p->dest=0;p->next=0;
        head[i]=p;tail[i]=p;
    }
    for (int i=1;i<=n-1;i++)
    {
        scanf("%d %d",&x1,&y1);
        mpush(x1,y1);mpush(y1,x1);
    }
    memset(hash,0,sizeof(hash));
    memset(fa,0,sizeof(fa));
    o=0;
    dfs(1);
    printf("%d\n",o);
    for (int i=1;i<=o;i++) printf("2 %d %d\n",f[i].first,f[i].second);
    for (int i=2;i<=o;i++)
        if (fa[f[i].first]==0) printf("%d %d\n",1,i); else printf("%d %d\n",fa[f[i].first],i);

    return 0;
}