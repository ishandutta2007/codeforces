#include<bits/stdc++.h>
using namespace std;
int a[12345];
int main()
{
	int n;
	int a,b;
	int c,d;
	int e,f;
	int flag = 0;
	scanf("%d",&n);
	scanf("%d %d",&a,&b);
	scanf("%d %d",&c,&d);
	scanf("%d %d",&e,&f);
	if((c-a)*(e-a)>0&&(d-b)*(f-b)>0) 
	{
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}