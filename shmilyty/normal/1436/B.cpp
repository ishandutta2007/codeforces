#include<bits/stdc++.h>
using namespace std;
int t,n;
bool pri(int x)
{
	if(x<2)
		return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int l=1;l<=n;l++)
				if(l==i||l==i%n+1)
					cout<<1<<" ";
				else
					cout<<0<<" ";
			cout<<endl;
		}
	}
	return 0;
}