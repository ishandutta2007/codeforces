#include<bits/stdc++.h>
using namespace std;
int a[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		set<int> s;
		int fg = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			s.insert(a[i] + 1);
			if(a[i] == 1) fg = 1;
		}
		if(fg == 0)
		{
			printf("YES\n");
			continue;
		}
		int fg2 = 0;
		for(int i = 0; i < n; i++)
		{
			if(s.find(a[i]) != s.end()) fg2 = 1;
		}
		if(fg2 == 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}