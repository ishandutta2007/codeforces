#include <iostream>
#include <map>
# include <stdio.h>
# include <algorithm>
# include <string>
using namespace std;
int a[100003];
int b[100003];
int main()
{
	int most=2;
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	b[0]=1;
	b[1]=2;
	for (int i=2;i<n;i++)
	{
		if (a[i]==a[i-1]+a[i-2])
		{
			b[i]=b[i-1]+1;
			if (b[i]>most)
				most=b[i];
		}
		else
			b[i]=2;
	}
	if (most>n)
		cout<<n<<endl;
	else
		cout<<most<<endl;
}