#include <cstdio>
using namespace std;
struct sublayer
{
	int v[1005];
	int& operator [] (int x)
	{
		return v[x+502];
	}
};
struct layer
{
	sublayer v[1005];
	sublayer& operator [] (int x)
	{
		return v[x+502];
	}
};
layer L;
sublayer lm,rm;
sublayer dl,dr;
int n,m,r;
int i,j,x,y;
int v[505][505];
int s[505][505];
int lp[505][505],rp[505][505];
int lc[505][505],rc[505][505];
long long ansx,ansy;
int main()
{
	scanf("%d%d%d",&n,&m,&r);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%d",&v[i][j]);
	for (i=-r;i<=r;i++)
	{
		for (j=-r;j<=r;j++)
			if (i*i+j*j<=r*r)
			{
				L[i][j]=1;
				rm[i]=j;
			}
		for (j=r;j>=-r;j--)
			if (L[i][j])
				lm[i]=j;
	}
	for (i=r+1;i<=n-r;i++)
	{
		for (x=-r;x<=r;x++)
			for (y=-r;y<=r;y++)
				if (L[x][y])
					s[i][r+1]+=v[i+x][r+1+y];
		for (j=r+2;j<=m-r;j++)
		{
			s[i][j]=s[i][j-1];
			for (x=-r;x<=r;x++)
			{
				s[i][j]-=v[i+x][j-1+lm[x]];
				s[i][j]+=v[i+x][j+rm[x]];
			}
		}
		for (j=r+1;j<=m-r;j++)
		{
			lp[i][j]=lp[i][j-1];
			lc[i][j]=lc[i][j-1];
			if (s[i][j]>lp[i][j])
			{
				lp[i][j]=s[i][j];
				lc[i][j]=0;
			}
			if (s[i][j]==lp[i][j])
				lc[i][j]++;
		}
		for (j=m-r;j>=r+1;j--)
		{
			rp[i][j]=rp[i][j+1];
			rc[i][j]=rc[i][j+1];
			if (s[i][j]>rp[i][j])
			{
				rp[i][j]=s[i][j];
				rc[i][j]=0;
			}
			if (s[i][j]==rp[i][j])
				rc[i][j]++;
		}
	}
	for (i=0;i<=n;i++)
	{
		for (j=-r;j<=r;j++)
			if (j-i>=-r)
				if (rm[j-i]+1-lm[j]>dl[i])
					dl[i]=rm[j-i]+1-lm[j];
		dr[i]=dl[i];
		if (dr[i]==0)
			dr[i]++;
	}
	for (i=r+1;i<=n-r;i++)
		for (j=r+1;j<=m-r;j++)
			for (x=r+1;x<=n-r;x++)
			{
				if (j-dl[x-i<0?i-x:x-i]>=r+1)
				{
					if (s[i][j]+lp[x][j-dl[x-i<0?i-x:x-i]]>ansx)
					{
						ansx=s[i][j]+lp[x][j-dl[x-i<0?i-x:x-i]];
						ansy=0;
					}
					if (s[i][j]+lp[x][j-dl[x-i<0?i-x:x-i]]==ansx)
						ansy+=lc[x][j-dl[x-i<0?i-x:x-i]];
				}
				if (j+dr[x-i<0?i-x:x-i]<=m-r)
				{
					if (s[i][j]+rp[x][j+dr[x-i<0?i-x:x-i]]>ansx)
					{
						ansx=s[i][j]+rp[x][j+dr[x-i<0?i-x:x-i]];
						ansy=0;
					}
					if (s[i][j]+rp[x][j+dr[x-i<0?i-x:x-i]]==ansx)
						ansy+=rc[x][j+dr[x-i<0?i-x:x-i]];
				}
			}
	printf("%lld %lld\n",ansx,ansy/2ll);
	return 0;
}