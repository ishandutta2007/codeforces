#include<bits/stdc++.h>
using namespace std;
int t,n,a[41];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int x=0,y=0;
		for(int i=1;i<=n;i+=2)
			if(a[i]%2==1)
				x++;
		for(int i=2;i<=n;i+=2)
			if(a[i]%2==0)
				y++;
		if(x!=y)
			puts("-1");
		else
			cout<<x<<endl;
	}
	return 0;
}