#include<bits/stdc++.h>

using namespace std;

const int maxn=1000010;

int a[maxn];

int s,n,m;

vector <int> v[maxn>>1];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		v[i].push_back(x);
		for(int j=1;j<=x;j++)
		{
			int y;
			scanf("%d",&y);
			v[i].push_back(y);
		}
	}
	for(int i=1;i<n;i++)
	{
		int len=min(v[i].size(),v[i+1].size());
		for(int j=1;j<len;j++)
		{
			if(v[i][j]>v[i+1][j])
			{
				a[m-v[i][j]+1]++;
				a[m-v[i+1][j]+1]--;
				//printf("[%d %d]\n",m-v[i][j]+1,m-v[i+1][j]+1);
				break;
			}
			else if(v[i][j]<v[i+1][j])
			{
				a[0]++;
				a[m-v[i+1][j]+1]--;
				a[m-v[i][j]+1]++;
				a[m]--;
				//printf("%d %d %d %d\n",0,m-v[i+1][j]+1,m-v[i][j]+1,m);
				break;
			}
			if(j==len-1)
			{
				if(v[i].size()<=v[i+1].size())
				{
					a[0]++;
					a[m]--;
					//printf("%d %d\n",0,m);
				}
				else
				{
					printf("-1");
					return 0;
				}
			}
		}
	}
	s=0;
	for(int i=0;i<=m;i++)
	{
		s+=a[i];
		if(s==n-1)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}