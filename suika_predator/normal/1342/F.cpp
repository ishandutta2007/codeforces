#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int T,n,m,k;
inline int hibit(int x){return 31-__builtin_clz(x);}
int f[23][23][33333];
pair<int,int> ls[23][23][33333];
int a[23],s[33333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int j=1;j<(1<<n);j++)
		{
			s[j]=a[hibit(j)]+s[j-(1<<hibit(j))];
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n;j++)
				memset(f[i][j],0x3f,sizeof(int)*((1<<n)+5));
		for(int mask=1;mask<(1<<n);mask++)
		{
			f[1][__builtin_ctz(mask)][mask]=s[mask];
		}
		for(int i=1;i<n;i++)
		{
			for(int mask=1;mask<(1<<n);mask++)
			{
				for(int j=0;j<n;j++)
				{
					if(!(mask&(1<<j)))continue;
					int cur=f[i][j][mask];
					if(cur==inf)continue;
					int t=(1<<n)-1-mask;
					if(s[t]<=cur)continue;
					for(int mask2=t;mask2;mask2=(mask2-1)&t)
					{
						if(hibit(mask2)<j)break;
						if(s[mask2]<=cur)continue;
						int a=i+1,b=mask|mask2,c=__builtin_ctz((~((1<<j)-1))&mask2);
						if(f[a][c][b]>s[mask2])
						{
//							cerr<<"tr "<<i<<' '<<j<<' '<<mask<<' '<<a<<' '<<c<<' '<<b<<' '<<s[mask2]<<endl;
							f[a][c][b]=s[mask2];
							ls[a][c][b]=make_pair(j,mask);
						}
					}
				}
			}
		}
		int a=0,b=0;
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<n;j++)
			{
				if(f[i][j][(1<<n)-1]!=inf)
				{
					a=i;
					b=j;
					break;
				}
			}
			if(a)break;
		}
		cout<<n-a<<endl;
		int cur=(1<<n)-1;
		int fl[23]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
		while(cur)
		{
			auto &t=ls[a][b][cur];
			int diff=cur-t.second;
//			cerr<<a<<' '<<b<<' '<<cur<<' '<<diff<<endl;
			for(int i=0;i<n;i++)
			{
				if(i!=b&&(diff&(1<<i)))
				{
					int u=0,v=0;
					for(int j=0;j<=i;j++)u+=fl[j];
					for(int j=0;j<=b;j++)v+=fl[j];
					cout<<u<<' '<<v<<endl;
					fl[i]=0;
				}
			}
			a--;
			b=t.first;
			cur=t.second;
		}
	}
	return 0;
}