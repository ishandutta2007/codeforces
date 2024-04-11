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
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}