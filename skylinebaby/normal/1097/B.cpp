#include<bits/stdc++.h>
using namespace std;
int a[360];
int b[360];
int main()
{
	int n;
	b[0] = 1;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<360;j++) a[j] = b[j];
		memset(b,0,sizeof(b));
		int x;
		scanf("%d",&x);
		for(int j = 0;j<360;j++) if(a[j]) b[(j+x)%360] = b[(j-x+360)%360] = 1;			
	}
	if(b[0]) printf("YES\n");
	else printf("NO\n");
	return 0;
}