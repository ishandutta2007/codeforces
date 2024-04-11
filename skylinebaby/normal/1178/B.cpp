#include<bits/stdc++.h>
using namespace std;
char s[1234567];
long long a[1234567];
int main()
{
	cin >> s;
	int n = strlen(s);
	long long ans = 0;
	long long sum = 0;
	a[0] = 0;
	for(int i = 0;i<n-1;i++)
	{
		if(s[i]=='v'&&s[i+1]=='v') sum++;		
		a[i+1] = sum;
	}
	for(int i = 0;i<n;i++) if(s[i]=='o') ans += a[i]*(sum-a[i]);
	printf("%lld\n",ans);
}