#include<bits/stdc++.h>
using namespace std;
char a[1010101];
char b[1010101];
int main()
{
	int n;scanf("%d",&n);
	cin>>a;
	a[n] = '0';
	cin>>b;
	b[n] = '0';
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		if (a[i]==b[i]) continue;
		if (a[i]==b[i+1]&&a[i+1]==b[i])
		{
			ans ++;
			i++;
			continue;
		}
		ans++;
	}
	printf("%d\n",ans);
}