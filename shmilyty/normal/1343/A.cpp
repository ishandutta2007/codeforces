#include<bits/stdc++.h>
using namespace std;
int t,n,now;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		now=4;
		while(n%(now-1)!=0)
			now*=2;
		cout<<n/(now-1)<<endl;
	}
	return 0;
}