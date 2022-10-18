#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main()
{
	int n,d,m;
	scanf("%d %d",&n,&d);
	scanf("%d",&m);
	for(int i = 0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x<y) swap(x,y);
		if(x+y>=d&&x+y<=2*n-d&&x-y<=d) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}