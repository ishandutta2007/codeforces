# include <iostream>
# include <map>
# include <string>
# include <cstdio>
# include <queue>
# include <list>
int a[10000];
int x[10000];
int y[10000];
using namespace std;
bool intersect(int a,int b,int c,int d)
{
	if ((a<min(d,c) || a>max(d,c))&& b<max(c,d) && b>min(c,d))
		return 1;
	if ((b<min(d,c) || b>max(d,c))&& a<max(c,d) && a>min(c,d))
		return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	bool p=1;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<n-1;i++)
	{
		x[i]=a[i];
		y[i]=a[i+1];
	}
	for (int i=0;i<n-1;i++)
	{
		for (int f=i-1;f>=0;f--)
		{
			if (intersect(x[i],y[i],x[f],y[f]))
			{
				p=0;
				break;
			}
		}
		if (p==0)
			break;
	}
	if (p==0)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}