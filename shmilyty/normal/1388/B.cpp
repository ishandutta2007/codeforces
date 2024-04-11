#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=(n+3)/4;
		for(int i=1;i+ans<=n;i++)
			cout<<9;
		for(int i=1;i<=ans;i++)
			cout<<8;
		cout<<endl;
	}
	return 0;
}