#include<bits/stdc++.h>
using namespace std;
int w[212345];
int deg[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		vector<int> haha;
		for(int i = 0; i < n; i++) deg[i] = -1;
		for(int i = 0; i < n; i++) scanf("%d", &w[i]);
		for(int i = 0; i < n - 1; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			deg[x - 1] ++;
			deg[y - 1] ++;
		}
		for(int i = 0; i < n; i++) 
		{
			for(int j = 0; j < deg[i]; j++) 
				haha.push_back(w[i]);
		}
		sort(haha.begin(), haha.end());
		reverse(haha.begin(), haha.end());
		long long ans = 0; 
		for(int i = 0; i < n; i++) ans += w[i];
		printf("%lld", ans);
		for(int i = 0; i < (int)haha.size(); i++)
		{
			ans += haha[i];
			printf(" %lld", ans);
		}
		printf("\n");
	}

	return 0;
 }