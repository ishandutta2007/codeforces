#include <bits/stdc++.h>
using namespace std;
const int N=2e5+20,M=1<<17;
char s[N];
int nxt[N][17],sum[N][17],f[M];
int n,m,q,l,r,mid,i,j;
bool pd(int len)
{
	for (i=0;i+1<len;i++) fill(nxt[n-i],nxt[n-i]+m,n+2);
	for (i=n-len+1;i;i--) for (j=0;j<m;j++) if (sum[i][j]-sum[i+len][j]==len) nxt[i][j]=i+len; else nxt[i][j]=nxt[i+1][j];
	fill(f+1,f+q,n+2);f[0]=1;
	for (i=1;i<q;i++) for (j=0;j<m;j++) if (i>>j&1) f[i]=min(f[i],nxt[f[i^1<<j]][j]);
	return f[q-1]!=n+2;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s+1;q=1<<m;
	for (i=1;i<=n;i++) s[i]=s[i]=='?'?m:s[i]-'a';
	for (i=n;i;i--)
	{
		memcpy(sum[i],sum[i+1],sizeof sum[0]);
		if (s[i]<m) ++sum[i][s[i]]; else for (j=0;j<m;j++) ++sum[i][j];
	}
	for (i=0;i<m;i++) nxt[n+1][i]=nxt[n+2][i]=n+2;
	l=0;r=n/m;
	while (l<r)
	{
		mid=l+r+1>>1;
		if (pd(mid)) l=mid; else r=mid-1;
	}
	cout<<l<<endl;
}