#include<bits/stdc++.h>
using namespace std;
int ar[1234];
int b[1234];
int main()
{
	int n;
	long long h;
	scanf("%d %lld",&n,&h);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	int pos = 1;
	while(pos<=n)
	{
		memset(b,0,sizeof(b));
		for(int i = 0;i<pos;i++)
		{
			b[i] = ar[i];
		}
		sort(b,b+pos);
		reverse(b,b+pos);
		long long ans = 0;
		for(int i = 0;i<pos;i+=2)
		{
			ans += (long long)max(b[i],b[i+1]);
		}
		if(ans>h) break;
		pos++;
	}
	printf("%d\n",pos-1);
	return 0;
}