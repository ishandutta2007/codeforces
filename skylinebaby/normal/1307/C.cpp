#include<bits/stdc++.h>
using namespace std;
char a[123456];
long long  s[300];
int main()
{
	cin >> a;
	long long ans = 0;
	int n = strlen(a);
	//printf("%d\n", n);
	for(int i = 0; i < 26; i++)
	{
		char c = 'a' + i;
		for(int j = 0; j < n; j++)
		{
			if(a[j] == c) s[i]++;
		}
		ans = max(ans, s[i]);
		ans = max(ans, s[i] * (s[i] - 1) / 2);
	}  
	//printf("%d\n", ans);
	for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) 
	{
		if(i == j) continue;
		long long sum = 0;
		long long cnt = 0;
		for(int k = 0; k < n; k++)
		{
			if(a[k] == 'a' + i) cnt ++;
			if(a[k] == 'a' + j) sum += cnt;
 		}
 		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}