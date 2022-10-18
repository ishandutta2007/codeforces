#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],buc[N*2],*fir=buc+N,cnt[102];
int main()
{
	int n,i,j,m;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;m=min(n,100);
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) ++cnt[a[i]];
	int x=max_element(cnt+1,cnt+m+1)-cnt;
	j=0;
	for (i=1;i<=m;i++) j+=cnt[i]==cnt[x];
	if (j>1) return cout<<n<<endl,0;
	int ans=0;
	for (j=1;j<=m;j++) if (j!=x)
	{
		static int b[N],s[N];
		memset(fir-n,0x3f,(n<<1|1)*sizeof fir[0]);
		for (i=1;i<=n;i++) if (a[i]==j) b[i]=1; else if (a[i]==x) b[i]=-1; else b[i]=0;
		for (i=1;i<=n;i++) s[i]=s[i-1]+b[i];
		for (i=0;i<=n;i++) ans=max(ans,i-fir[s[i]]),fir[s[i]]=min(fir[s[i]],i);
	}
	cout<<ans<<endl;
}