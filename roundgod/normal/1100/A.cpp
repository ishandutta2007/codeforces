#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    int s0=0,s1=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1) s0++; else s1++;
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        int cnt0=0,cnt1=0;
        if(a[i]==1) cnt0++; else cnt1++;
        for(int j=i+k;j<=n;j+=k) if(a[j]==1) cnt0++; else cnt1++;
        ans=max(ans,abs(s0-cnt0-s1+cnt1));
    }
    printf("%d\n",ans);
    return 0;
}