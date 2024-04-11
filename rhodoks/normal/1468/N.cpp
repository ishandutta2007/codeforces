#include <bits/stdc++.h>

using namespace std;

int a1,a2,a3,a4,a5;
int c1,c2,c3;

void work()
{
	scanf("%d%d%d%d%d%d%d%d",&c1,&c2,&c3,&a1,&a2,&a3,&a4,&a5);
	c1-=a1;
	c2-=a2;
	c3-=a3;
	if (c1<0 || c2<0 || c3<0)
	{
		cout<<"NO"<<endl;
		return ;
	}
	a4-=min(c1,a4);
	a5-=min(c2,a5);
	c3-=a4+a5;
	if (c3<0)
	{
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
}

int main()
{
	int t;
	cin>>t;
	while (t--)
			work();
	return 0;
}