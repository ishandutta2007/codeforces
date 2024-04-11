#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,v=0;
		long long y;
		scanf("%d%d%lld",&n,&x,&y);
		while(n--)
		{
			int z;
			scanf("%d",&z);
			v=(v+z)&1;
		}
		if(((x&1)^v)==(y&1))
			puts("Alice");
		else
			puts("Bob");
	}
	return 0;
}