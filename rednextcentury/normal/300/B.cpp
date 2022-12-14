# include <iostream>
# include <string>
# include <map>
# include <cmath>
# include <algorithm>
# include <vector>
using namespace std;
vector<int> a[100];
int b[10000];
int c[10000];
bool d[1000];
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		cin>>b[i]>>c[i];
		if (d[c[i]]+d[b[i]]==2)
			continue;
		if (d[c[i]]==0 && d[b[i]]==0)
		{
			a[c[i]].push_back(c[i]);
			a[c[i]].push_back(b[i]);
		}
		else if(d[b[i]]==1)
		{
			for (int j=1;j<=n;j++)
			{
				for (int x=0;x<a[j].size();x++)
				{
					if (a[j][x]==b[i])
						a[j].push_back(c[i]);
				}
			}
		}
		else if(d[c[i]]==1)
		{
			for (int j=1;j<=n;j++)
			{
				for (int x=0;x<a[j].size();x++)
				{
					if (a[j][x]==c[i])
						a[j].push_back(b[i]);
				}
			}
		}
		d[c[i]]=1;
		d[b[i]]=1;
	}
	bool p=0;
	int ans=0;
	int u=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i].size()>3)
		{
			p=1;
			break;
		}
	}
	
	if (p==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i].size()>0)
			{
				u++;
			}
		}
		if (u>n/3)
		{
			cout<<-1<<endl;
			return 0;
		}
		for (int i=1;i<=n;i++)
		{
			if (a[i].size()==0)
				continue;
			else if (a[i].size()==3)
			{
				cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
				ans++;
			}
			else
			{
				ans++;
				cout<<a[i][0]<<" "<<a[i][1]<<" ";
				for (int x=1;x<=n;x++)
				{
					if (d[x]==0)
					{
						d[x]=1;
						cout<<x<<endl;
						break;
					}
				}
			}
		}
		for (;ans<n/3;ans++)
	{
		for (int i=1;i<=n;i++)
		{
			if (d[i]==0)
			{
				d[i]=1;
				cout<<i;
				break;
			}
		}
		for (int x=0;x<2;x++)
		{
			for (int i=1;i<=n;i++)
			{
				if (d[i]==0)
				{
					d[i]=1;
					cout<<" "<<i;
					break;
				}
			}
		}
		cout<<endl;
	}
	}
	
}