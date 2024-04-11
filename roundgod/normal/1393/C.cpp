#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN],cnt[MAXN];
vector<P> v;
int ans[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        v.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        int maxi=0;
        for(int i=1;i<=n;i++) maxi=max(maxi,cnt[i]);
        int s=0;
        for(int i=1;i<=n;i++) if(cnt[i]==maxi) s++;
        printf("%d\n",(n-s)/(maxi-1)-1);
    }
}