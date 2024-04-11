#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 105

using namespace std;

char s[maxn]; 
int ans,n,m;

int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	s[n]='0';m=0;
	for (int i=0;i<=n;i++)
	{
		if (s[i]=='0'){
			printf("%d",m);
			m=0;
		}
		else m++;
	}
	printf("\n");
	return 0;
}