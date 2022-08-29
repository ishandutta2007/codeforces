#include<stdio.h>
#define MAXN 110000
using namespace std;
bool pr[MAXN];
bool cho[MAXN];
int t[MAXN];
int lj[MAXN];
int n;
int x[MAXN],y[MAXN];int ans=0;
void init()
{
     for(int i=2;i<=n;i++)
     if(!pr[i])
     for(int j=i*2;j<=n;j+=i)pr[j]=1;
}
int main()
{
    scanf("%d",&n);init();
    for(int i=n/2;i>=2;i--)
    if(!pr[i])
    {
            t[t[0]=1]=i;
            for(int j=i*2;j<=n;j+=i)
            if(!cho[j])
            {
                       cho[j]=1;t[++t[0]]=j;
                       }
            if(t[0]&1)
            {
                      lj[++lj[0]]=2*i;
                      t[2]=t[1];
                      for(int k=2;k<t[0];k+=2)
                      {
                              ++ans;x[ans]=t[k];y[ans]=t[k+1];
                              }
                              }
            else
            {
                for(int k=1;k<t[0];k+=2)
                {
                        ++ans;x[ans]=t[k];y[ans]=t[k+1];
                        }
                        }
                        }
    for(int i=1;i<lj[0];i+=2)
    {
            ++ans;x[ans]=lj[i];y[ans]=lj[i+1];
            }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)printf("%d %d\n",x[i],y[i]);
    return 0;
}