#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i*2<=n;i++)
		{
			scanf("%d %d",&a,&b);
			cout<<-b<<" "<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}