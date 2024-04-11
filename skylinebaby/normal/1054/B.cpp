#include<bits/stdc++.h>
using namespace std;
int a[123456];
int b[123456];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%d",&a[i]);
	int pos = 0;
	for(int i = 0;i<n;i++)
	{
		if(a[i]>pos) 
		{
			printf("%d\n",i+1);
			return 0;
		}
		b[a[i]]++;
		while(b[pos])
		{
			pos++;
		}
	}
printf("-1\n");

	return 0;
}