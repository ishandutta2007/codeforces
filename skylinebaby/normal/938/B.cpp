#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int x = 0;
	for(int i = 0;i<n;i++)
	{
		int y;
		scanf("%d",&y);
		int t = min(y-1,1000000-y);
		x = max (t,x);
	}	
	printf("%d\n",x);
	return 0;
}