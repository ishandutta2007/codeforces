#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int pos = 0;
	int neg = 0;
	for(int i = 0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if (x>0) pos++;
		else neg++;
	}
	if (pos<=1||neg<=1) printf("Yes\n");
	else printf("No\n");
	return 0;
}