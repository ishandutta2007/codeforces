#include<bits/stdc++.h>
using namespace std;
char a[200];
int main()
{
	int n;
	scanf("%d",&n);
	cin >> a;
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		if(a[i]=='8') sum++;
	}
	printf("%d\n",min(sum,n/11));
	return 0;
}