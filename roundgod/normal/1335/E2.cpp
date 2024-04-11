#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
vector<int> pos[205];
int sum[205][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=200;i++) fill(sum[i],sum[i]+n+1,0);
        for(int i=1;i<=200;i++) pos[i].clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            pos[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=200;j++)
            {
                if(a[i]==j) sum[j][i]=sum[j][i-1]+1;
                else sum[j][i]=sum[j][i-1];
            }
        }
        int ans=0;
        for(int i=1;i<=200;i++) ans=max(ans,(int)pos[i].size());
        for(int i=1;i<=200;i++)
        {
            for(int j=0;j<(int)pos[i].size()/2;j++)
            {
                int st=pos[i][j],ed=pos[i][(int)pos[i].size()-1-j];
                for(int k=1;k<=200;k++) 
                {
                    if(k==i) continue;
                    ans=max(ans,2*(j+1)+sum[k][ed]-sum[k][st]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}