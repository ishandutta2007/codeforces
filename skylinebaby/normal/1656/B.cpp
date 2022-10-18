#include<bits/stdc++.h>
using namespace std;
int a[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		set<int> s;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			s.insert(a[i] + k);
		}
		int fg = 0;
		for(int i = 0; i < n; i++)
		{
			if(s.find(a[i]) != s.end()) fg = 1;
		}
		if(fg == 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}