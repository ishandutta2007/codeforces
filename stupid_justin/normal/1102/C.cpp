#include<bits/stdc++.h>
using namespace std;
int n,x,y,num,ans,a;
int main()
{
	cin>>n>>x>>y;
	if (x>y)
	{
		cout<<n<<endl;
	}
	else
	{
		for (int i=1;i<=n;++i)
		{
			cin>>a;
			if (a<=x) num++;
		}
		cout<<(num+1)/2<<endl;
	}
	return 0;
}