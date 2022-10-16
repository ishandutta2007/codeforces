#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	printf("%d\n0 0\n",3*n+4); 
	for(int i=1;i<=n+1;i++)
		printf("%d %d\n%d %d\n%d %d\n",i-1,i,i,i-1,i,i);
	return 0;
}