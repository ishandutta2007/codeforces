#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int a[105][105],qwq[105][105];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			qwq[i][j]=1+(i+j&1);
	for(int i=1;i<=n*n;i++)
	{
		int x;
		cin >> x;
		if(x==3)
		{
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(!a[i][j])
					{
						cout << qwq[i][j] << " " << i << " " << j   << endl;
						a[i][j]=qwq[i][j];
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
		}
		if(x==2)
		{
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(!a[i][j]&&qwq[i][j]==1)
					{
						cout << qwq[i][j] << " " << i << " " << j  << endl;
						a[i][j]=qwq[i][j];
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
			if(!flag)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(!a[i][j])
						{
							cout << 3 << " "<< i << " " << j << endl;
							a[i][j]=3;
							flag=1;
							break;
						}
					}
					if(flag) break;
				}
			}
		}
		if(x==1)
		{
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(!a[i][j]&&qwq[i][j]==2)
					{
						cout << qwq[i][j] << " " << i << " " << j  << endl;
						a[i][j]=qwq[i][j];
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
			if(!flag)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(!a[i][j])
						{
							cout << 3 << " "<< i << " " << j << endl;
							a[i][j]=3;
							flag=1;
							break;
						}
					}
					if(flag) break;
				}
			}
		}
	}
	return 0;
}