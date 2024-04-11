#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 1020

using namespace std;  
  
int a[maxn],n,m,t;
char s[maxn];

int main()  
{
	scanf("%d",&n);
	scanf("%s",s);
	m=0;t=0;
	while (t<n)
	{
		while (s[t]=='B'&&t<n)
		{
			t++;a[m]++;
		}
		if (a[m]) m++;
		t++;
	}
	printf("%d\n",m);
	for (int i=0;i<m-1;i++)
	    printf("%d ",a[i]);
	if (m) printf("%d\n",a[m-1]);
	return 0;
}