#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int L[MAXN],R[MAXN];
int st[MAXN];
int sum[MAXN];
int maxlen[MAXN];
void solve()
{
	int t=0;
	for(int i=1;i<=n;i++)
	{
		while(t>0&&a[st[t-1]]>=a[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=n;i>=1;i--)
	{
		while(t>0&&a[st[t-1]]>=a[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n+1;i++) sum[i]=maxlen[i]=0;
        solve();
        for(int i=1;i<=n;i++)
        {
            maxlen[a[i]]=max(maxlen[a[i]],R[i]-L[i]-1);
        }
        for(int i=1;i<=n;i++)
        {
            if(maxlen[i]>0)
            {
                sum[1]++;
                sum[min(maxlen[i]+1,n+2-i)]--;
            }
        }
        for(int i=2;i<=n;i++) sum[i]+=sum[i-1];
        for(int i=1;i<=n;i++) printf("%d",sum[i]==n-i+1?1:0);
        puts("");
    }
    return 0;
}