#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%4)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i*2<=n;i++)
			cout<<i*2<<" ";
		for(int i=1;i*2<n;i++)
			cout<<i*2-1<<" ";
		cout<<(n/2)*(n/2+1)-(n/2-1)*(n/2-1)<<endl;
	}
	
	return 0;
}