#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	long long a,b;
	a = 1;
	b = 1;
	for(int i = 0;i<n;i++)
	{
		char c[5];
		cin>>c;
		if (strlen(c)==4) {
			a++;
			b++;
			continue;
		}
		if(c[0]=='U')
		{
			if (c[1]=='L') a++;
			else b++;
		}
		else {
			if(c[1]=='L') b++;
			else a++;
		}
	}
	long long x = a*b;
	cout<<x<<'\n';
	return 0;
}