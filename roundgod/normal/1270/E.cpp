#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    while(true)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if((x[i]+y[i])&1) cnt++;
        }
        if(cnt!=0&&cnt!=n)
        {
            printf("%d\n",cnt);
            for(int i=1;i<=n;i++) if((x[i]+y[i])&1) printf("%d ",i);
            puts("");
            exit(0);
        }
        else if(cnt==0)
        {
            for(int i=1;i<=n;i++) 
            {
                int xx=(x[i]+y[i])/2,yy=(x[i]-y[i])/2;
                x[i]=xx; y[i]=yy;
            }
        }
        else 
        {
            for(int i=1;i<=n;i++) x[i]++;
        }
    }
    return 0;
}