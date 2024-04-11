#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2050;

int n,m;
int a[maxn][maxn],b[maxn][maxn];
int d[maxn];

int qi[maxn],qj[maxn],head,tail;
int qt[maxn];
ll dis(ll x,ll y){ return x*x+y*y; }
int cal(int x1,int y1,int x2,int y2)
{
	//x1 < x2
	int l=1,r=m;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if( dis(x1-mid,y1)>=dis(x2-mid,y2) ) r=mid-1;
		else l=mid+1;
	}
	return r+1;
}

ll ans[maxn][maxn],tans[maxn][maxn];
void solve()
{
	for(int j=1;j<=m;j++) d[j]=0;
	for(int i=1;i<=n;i++)
	{
		head=1,tail=0;
		
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]) d[j]=i;
			
			if(d[j])
			{
				++tail;
				qi[tail]=d[j],qj[tail]=j;
				if(head<tail) qt[tail-1]=cal(qj[tail-1],i-qi[tail-1],j,i-d[j]);
				while(head+1<tail&&qt[tail-2]>=qt[tail-1])
				{
					tail--;
					qi[tail]=d[j],qj[tail]=j;
					qt[tail-1]=cal(qj[tail-1],i-qi[tail-1],j,i-d[j]);
				}
			}
			while(head<tail&& qt[head]<=j) head++;
			
			if(head<=tail)
				ans[i][j]=min(ans[i][j],dis(qi[head]-i,qj[head]-j));
		}
	}
}

char str[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m; n++,m++;
	for(int i=1;i<=n;i++) 
	{
		cin>>(str+1);
		for(int j=1;j<=m;j++)
		{
			a[i][j]=str[j]-'0';
			ans[i][j]=LLONG_MAX;
		}
	}
	
	for(int K=0;K<4;K++)
	{
		solve();
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
			b[m-j+1][i]=a[i][j];
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
			tans[m-j+1][i]=ans[i][j];
		swap(n,m);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=b[i][j];
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans[i][j]=tans[i][j];
	}
	
	ll re=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		re+=ans[i][j];
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
			cout<<ans[i][j]<<" \n"[j==m];
	}*/
	cout<<re<<endl;
	
	return 0;
}