#include<bits/stdc++.h>
using namespace std;
int a[1234];
int b[1234];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
	int k;
	scanf("%d",&k);
	int pos = 0;
	while(pos<n)
	{
		if(b[pos]<k) pos++;
		else break; 
	}
	printf("%d\n",n-pos);
	return 0;
}