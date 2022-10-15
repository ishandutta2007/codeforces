#include<bits/stdc++.h>
#define MAXN 150005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
vector<int> pos[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            pos[a[i]].push_back(i);
        }
        int ans=-1;
        for(int i=1;i<=150000;i++)
        {
            if(pos[i].size()<2) continue;
            for(int j=0;j<(int)pos[i].size()-1;j++)
            {
                ans=max(ans,1+pos[i][j]-1+(n-pos[i][j+1]));
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) pos[a[i]].clear();
    }
    return 0;
}