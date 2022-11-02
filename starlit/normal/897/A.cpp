#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 110
using namespace std;
int n,m,l,r;
char s[N],a[2],b[2];
int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	while(m--)
	{
		scanf("%d%d%s%s",&l,&r,a,b);
		for(int i=l;i<=r;i++)
		if(s[i]==a[0])s[i]=b[0];
	}
	puts(s+1);
}