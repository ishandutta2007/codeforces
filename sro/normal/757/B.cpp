#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int n,s[123456],i,j;
int m[123456];

inline int gcd(int a,int b)
{
	int k;
	while(a%b)
	{
		k=a%b;
		a=b;
		b=k;
	}
}

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&s[i]);
	for(i=0;i<n;i++)
		for(j=1;j<=sqrt(s[i]);j++)
			if(s[i]%j==0)
			{
				m[j]++;
				m[s[i]/j]++;
				if(j==s[i]/j)m[j]--;
			}
	int maxv=1;
	for(int i=2;i<123456;i++)
		if(maxv<m[i])maxv=m[i];
	printf("%d",maxv);
	return 0;
}