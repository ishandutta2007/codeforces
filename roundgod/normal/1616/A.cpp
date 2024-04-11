#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            cnt[max(a[i],-a[i])]++;
        }
        int ans=0;
        for(int i=1;i<=100;i++) ans+=(min(cnt[i],2));
        if(cnt[0]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}