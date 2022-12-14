# include <iostream>
# include <string>
# include <algorithm>
# include <iomanip>
# include <cmath>
using namespace std;
bool a[100][101];
int g[100][100];
int b[100];
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		b[i]=m;
		for (int x=0;x<m;x++)
		{
			int h;
			cin>>h;
			g[i][x]=h;
			a[i][h]=1;
		}
	}
	for (int i=0;i<n;i++)
	{
		int c[100]={0};
		for (int i=0;i<n;i++)
			c[i]=b[i];
		int wins=0;
		bool p=0;
		for (int x=0;x<b[i];x++)
		{
			for (int v=0;v<n;v++)
			{
				if (a[v][g[i][x]]==1)
					c[v]--;
				if (c[v]==0)
				{
					wins++;
				}
			}
			if (wins>0)
			{
				if (wins==1 && c[i]==0)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
				break;
			}
		}
	}
}