#include<bits/stdc++.h>
using namespace std;
char a[312345];
int b[312345];
int n,m;
int solve(int x)
{
	int need = 0;
	if(a[0]>=m-x) need = 0;
	else need = a[0];
	for(int i = 1;i<n;i++)
	{
		if(a[i]<=need) 
		{
			if(need-a[i]>x) return 0;	
		}
		else 
		{
			if (a[i]+x<need+m) need = a[i];
		} 
	}
	return 1;
}
int main()
{
	cin >> a;
	long long n = strlen(a);
	for(int i = 0;i<n;i++)
	{
		if(a[i]=='0') b[i] = 0;
		else b[i] = 1;
	}
	if(n<=2)
	{
		printf("0\n");
		return 0; 
	 } 
	long long ans = n*(n-1)/2;
	ans -= n-1;
	for(int m = 3;m <= 10;m++)
	{
		for(int i = 0;i+m-1<n;i++)
		{
			int flag = 0;
			for(int j = i;j<=i+m-3;j++) for(int k = j+1;k<=i+m-2;k++)
			{
				if(2*k-j>i+m-1) continue;
				if(b[j]==b[k]&&b[k]==b[2*k-j]) flag = 1;
			}
			if(!flag) ans --;
 		}
	}
	printf("%lld\n",ans);
}