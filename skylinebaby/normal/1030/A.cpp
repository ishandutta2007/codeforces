#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main()
{
	int n;
	scanf("%d",&n);
	int flag = 0;
	for(int i = 0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1) flag = 1;
	}
	if(flag ) printf("HARD\n");
	else printf("EASY\n");
	return 0;
}