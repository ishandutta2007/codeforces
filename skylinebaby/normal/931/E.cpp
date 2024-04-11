#include<bits/stdc++.h>
using namespace std;
int a[800];
int b[26];
char s[5555];
int main()
{
	cin >> s;
	int n = strlen(s);
	int ans = 0;
	memset(b,0,sizeof(b));
	for(int i = 1;i<=n-1;i++)
	{
		memset(a,0,sizeof(a));
		for(int j = 0;j<n;j++)
		{
			int t = (j+i)%n;
			int x = ((s[j]-'a')*26+(s[t]-'a'));
			a[x]++;
		}
		for(int j = 0;j<26;j++)
		{
			int cnt = 0;
			for(int k = 0;k<26;k++)
			{
				if (a[j*26+k]==1) cnt++;
			}
			b[j]=max(b[j],cnt);
		}
	}
	for(int i = 0;i<26;i++) ans += b[i];
	double nee = (double)ans / (double)n;
	printf("%.10lf\n",nee);
	return 0;
}