#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int n,c;
	scanf("%d %d",&n,&c);
	int maa = 0;
	int pre;
	int now;
	scanf("%d",&now);
	for(int i = 1;i<n;i++)
	{
		pre = now;
		scanf("%d",&now);
		maa = max(maa,pre-now-c);
	}
	printf("%d\n",maa);
	return 0;
 }