#include<bits/stdc++.h>
using namespace std;
char a[123456];
int main()
{
	int n;
	scanf("%d",&n);
	cin>>a;
	int x= strlen(a);
	int sum = 0;
	for(int i = 0;i<x;i++)
	{
		sum += a[i]-'0';
	}
	int flag = 0;
	if(sum == 0) flag = 1;
	for(int i = 1;2*i<=sum;i++)
	{
		if(sum%i!=0) continue;
		int cnt = 0;
		for(int j = 0;j<x;j++)
		{
			if(cnt>i) break;
			if(cnt==i) cnt = 0;
			if(cnt<i) cnt += a[j]-'0';
		}
		 if(cnt == i||cnt == 0) flag = 1;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}