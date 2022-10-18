#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2,K=460;
vector<int> ap[N],de[N];
int a[N],b[N],c[N],st[N],dcf[N],cf[N],ans[N],cnt[K][K];
int n,m,i,j,x,y,z,siz;
void modify(int l,int r,int sp=1)
{
	//cout<<"modify "<<l<<' '<<r<<endl;
	r=min(r,m);assert(l-1<=r);
	cf[l]+=sp;cf[r+1]-=sp;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;siz=450;
	for (i=1;i<=n;i++) cin>>a[i]>>b[i],c[i]=a[i]+b[i];
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		if (x==1)
		{
			if (a[y]+i>m) continue;
			st[y]=a[y]+i;
		}
		else
		{
			if (!st[y]) continue;
			if (b[y]+st[y]>m)
			{
				if (st[y]>=i) {st[y]=0;continue;}
				modify(st[y],i-1);
				st[y]=0;
				continue;
			}
			if (st[y]<i)
			{
				ap[st[y]].emplace_back(y);
				//cout<<i-st[y]<<endl;
				if ((i-st[y])%c[y]<b[y])
				{
					z=(i-st[y])%c[y];//cout<<i-z<<' '<<i-1<<endl;
					modify(i-z,i-1);
					de[i-z].emplace_back(y);
				}
				else
				{
					z=(i-st[y])%c[y];
					modify(i-z,i-z+b[y]-1);
					de[i-z].emplace_back(y);
				}
			}
			st[y]=0;
		}
	}
	for (y=1;y<=n;y++) if (st[y])
	{
		i=m+1;
		if (b[y]+st[y]>m)
		{
			if (st[y]>=i) {st[y]=0;continue;}
			modify(st[y],i-1);
			st[y]=0;
			continue;
		}
		if (st[y]<i)
		{
			ap[st[y]].emplace_back(y);
			if ((i-st[y])%c[y]<b[y])
			{
				z=(i-st[y])%c[y];
				modify(i-z,i-1);
				de[i-z].emplace_back(y);
			}
			else
			{
				z=(i-st[y])%c[y];
				modify(i-z,i-z+b[y]-1);
				de[i-z].emplace_back(y);
			}
		}
		st[y]=0;
	}
	for (i=1;i<=m;i++)
	{
		for (auto u:ap[i])
		{
			//cout<<u<<' '<<i<<endl;
			x=a[u];y=b[u];z=c[u];
			if (z>=siz)
			{
				for (j=i;j<=m;j+=z) modify(j,j+y-1);
			}
			else
			{
				for (j=0;j<y;j++) ++cnt[z][(i+j)%z];
			}
		}
		for (auto u:de[i])
		{
			x=a[u];y=b[u];z=c[u];
			if (z>=siz)
			{
				for (j=i;j<=m;j+=z) modify(j,j+y-1,-1);
			}
			else
			{
				for (j=0;j<y;j++) --cnt[z][(i+j)%z];
			}
		}
		for (j=2;j<siz;j++) ans[i]+=cnt[j][i%j];
	}
	//for (i=1;i<=m;i++) cout<<ans[i]<<" \n"[i==m];
	for (i=1;i<=m;i++) cf[i]+=cf[i-1];
	for (i=1;i<=m;i++) cout<<ans[i]+cf[i]<<'\n';
}