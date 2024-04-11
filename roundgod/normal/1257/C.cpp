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
int last[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) last[i]=-1;\
        int ans=INF;
        for(int i=1;i<=n;i++)
        {
            if(last[a[i]]!=-1) ans=min(ans,i-last[a[i]]+1);
            last[a[i]]=i;
        }
        if(ans==INF) puts("-1"); else printf("%d\n",ans);
    }
    return 0;
}