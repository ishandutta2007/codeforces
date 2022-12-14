#include<iostream>
#include<string>
# include <queue>
#define FOR(i,n) for (int i=0;i<n;i++)
using namespace std;
struct d
{int a;int b;bool c;int before;};
d a[100005];
int main()
 {
	int n;
	cin>>n;
	int max=-1;
	int u=n;
	FOR(i,n)
	{
		int s;
		cin>>s;
		if (s>max)
			max=s;
		a[s].a++;
		if (a[s].a==2)
		{
			a[s].b=(i+1)-a[s].before;
		}
		if (a[s].a>2)
		{
			if ((i+1)-a[s].before!=a[s].b)
			{
				a[s].c=1;
				u--;
			}
		}
		a[s].before=i+1;
	}
	u=0;
	for (int i=1;i<=max;i++)
		if (a[i].a>0 && a[i].c==0)
			u++;
	cout<<u<<endl;
	for(int i=1;i<=max;i++)
	{
		if (a[i].a>0 && a[i].c==0)
			cout<<i<<" "<<a[i].b<<endl;
	}
 }