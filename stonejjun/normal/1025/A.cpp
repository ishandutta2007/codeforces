#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int arr[222222];
char c[222222];

int main()
{
	int n,m,i,j,k,a,b,x,y;
	int ans=0,sum=0,chk=0;
	scanf("%d",&n);
	scanf("%s",&c);
	
	if(n==1)
	{
		printf("YES");
		return 0;
	}
	
	for(i=0;i<n;i++)
	{
		arr[c[i]-'a']++;
	}
	
	for(i=0;i<30;i++)
	{
		if(arr[i]>=2) chk=1;
	}
	
	if(chk) printf("Yes");
	else printf("No");
	
	
	
}