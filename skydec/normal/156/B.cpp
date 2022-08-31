#include<cstdio>
#include<cstring>
#define MAXN 110000
using namespace std;
int nots[MAXN],is[MAXN];
char fh[MAXN];int to[MAXN];
int n,m;int istot,nottot;
bool can[MAXN];int tot=0;
inline char getnext()
{
       char p=getchar();
       while(p!='-'&&p!='+')p=getchar();
       return p;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
            char p=getnext();
            int v;scanf("%d",&v);
            if(p=='+')is[v]++,istot++;
            else nots[v]++,nottot++;
            fh[i]=p;to[i]=v;
            }
    for(int i=1;i<=n;i++)
    {
            int tru=0;
            tru=nottot-nots[i]+is[i];
            if(tru==m)can[i]=1,tot++;
            }
    for(int i=1;i<=n;i++)
    {
            int uccu=0;
            if(fh[i]=='+')
            {       
                  if(can[to[i]])uccu|=1;
                  if(tot-can[to[i]])uccu|=2;
                  }
            else
            {
                if(can[to[i]])uccu|=2;
                if(tot-can[to[i]])uccu|=1;
                }
            if(uccu==1)printf("Truth\n");
            else if(uccu==2)printf("Lie\n");
            else printf("Not defined\n");
            }
    return 0;
}