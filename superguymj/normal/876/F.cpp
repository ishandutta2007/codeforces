#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=200005,M=20;
int n,a[N],stk[N],L[N],R[N],LOR[N],ROR[N],len[N],st[M][N];
long long ans;

int query(int l,int r)
{
	int x=len[r-l+1];
	return st[x][l]|st[x][r-(1<<x)+1];
}

int findl(int l,int r,int x)
{
	while(l<=r)
	{
		if(query(mid,x)>a[x]) l=mid+1;
		else r=mid-1;
	}
	return l-1;
}

int findr(int l,int r,int x)
{
	while(l<=r)
	{
		if(query(x,mid)>a[x]) r=mid-1;
		else l=mid+1;
	}
	return r+1;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n)
	{
		while(*stk && a[stk[*stk]]<a[i]) R[stk[(*stk)--]]=i-1;
		stk[++*stk]=i;
	}
	while(*stk) R[stk[(*stk)--]]=n;
	repd(i,n,1)
	{
		while(*stk && a[stk[*stk]]<=a[i]) L[stk[(*stk)--]]=i+1;
		stk[++*stk]=i;
	}
	while(*stk) L[stk[(*stk)--]]=1;
	len[1]=0;
	rep(i,2,n) len[i]=len[i>>1]+1;
	rep(i,1,n) st[0][i]=a[i];
	rep(i,1,18)
		rep(j,1,n-(1<<i)+1)
			st[i][j]=st[i-1][j]|st[i-1][j+(1<<(i-1))];
	rep(i,1,n)
	{
		LOR[i]=findl(1,i,i);
		ROR[i]=findr(i,n,i);
	}
	rep(i,1,n)
	{
		if(LOR[i]>=L[i]) ans+=(LOR[i]-L[i]+1ll)*(R[i]-i+1ll);
		if(ROR[i]<=R[i]) ans+=(i-max(LOR[i]+1,L[i])+1ll)*(R[i]-ROR[i]+1ll);
	}
	printf("%I64d\n",ans);
	return 0;
}