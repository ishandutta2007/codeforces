#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,cnt[MAXN];
bool has[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=2*n+2;i++) cnt[i]=0,has[i]=false;
        for(int i=1;i<=n;i++) 
        {
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        int ans=0;
        for(int i=1;i<=2*n+1;i++)
        {
            if(cnt[i])
            {
                if(cnt[i]>=2)
                {
                    has[i]=true;
                    has[i+1]=true;
                }
                else if(has[i])
                {
                    has[i+1]=true;
                }
                else has[i]=true;
            }
            if(has[i]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}