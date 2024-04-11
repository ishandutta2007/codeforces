#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second
PII ff(int x,int y)
{
    if(x==1)
    {
        if(y==0)return mp(0,0);
        if(y==1)return mp(0,1);
        if(y==2)return mp(1,1);
        if(y==3)return mp(1,0);
    }
    int p=1<<x*2-2;
    if(y<p)
    {
        PII S=ff(x-1,y);
        return mp(S.se,S.fi);
    }
    if(y<p*2)
    {
        PII S=ff(x-1,y-p);
        return mp(S.fi,S.se+(1<<x-1));
    }
    if(y<p*3)
    {
        PII S=ff(x-1,y-p*2);
        return mp(S.fi+(1<<x-1),S.se+(1<<x-1));
    }
    if(y<p*4)
    {
        PII S=ff(x-1,y-p*3);
        return mp((1<<x)-1-S.se,(1<<x-1)-1-S.fi);
    }
}
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    PII S=ff(n,m);
    printf("%d %d\n",S.fi,S.se);
    return 0;
}