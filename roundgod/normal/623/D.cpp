#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n;
double p[MAXN],q[MAXN];
double ans;
const int MAGIC=300000;
double prob;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        p[i]=x/100.0; q[i]=1-p[i];
    }
    ans=n;
    prob=1.0;
    for(int i=1;i<=n;i++) prob*=p[i];
    for(int i=n+1;i<=MAGIC;i++)
    {
        ans+=1.0-prob;
        int id=-1;
        for(int j=1;j<=n;j++) if(id==-1||(1-q[j]*(1-p[j]))*p[id]>(1-q[id]*(1-p[id]))*p[j]) id=j;
        prob=prob/p[id];
        p[id]=1-(1-p[id])*q[id];
        prob=prob*p[id];
    }
    printf("%.10f\n",ans);
    return 0;
}