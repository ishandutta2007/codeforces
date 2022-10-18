#include<bits/stdc++.h>
using namespace std;
vector<long long> adj[123456];
int k[123456];
int y[123456];
pair<long long, int> need[123456];
long long z[123456];
long long p[123456];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		multiset<long long> s;
		for(int i = 0; i < n; i++)
		{
			long long x;
			scanf("%lld", &x);
			s.insert(x);
		}
		for(int i = 0; i < m; i++)
		{
			scanf("%d", &k[i]);
			z[i] = 0;
			long long sum = 0;
			for(int j = 0; j < k[i]; j++)
			{
				long long x;
				scanf("%lld", &x);
				adj[i].push_back(x);
				sum += x;
			}
			need[i] = make_pair((sum + k[i] - 1) / k[i], i); 
		}
		sort(need, need + m);
		int fg = m;
		for(int i = 0; i < m - 1; i++)
		{
			multiset<long long>::iterator it = s.lower_bound(need[i].first);
			if (it == s.end())
			{
				fg = i;
				break;
			}
			p[i] = *it;
			s.erase(it); 
		}
		if(fg < m - 1)
		{
			for(int i = 0; i < m; i++)
			{
				for(int j = 0; j < k[i]; j++)
				{
					printf("0");
				}
			}
			printf("\n");
			continue;
		}
		for(int i = m - 1; i >= 0; i--)
		{
			if(i == m - 1) z[i] = *max_element(s.begin(), s.end());
			else
			{
				s.insert(p[i]);
				multiset<long long>::iterator it = s.lower_bound(need[i + 1].first);
				if (it == s.end()) break;
				s.erase(it);
				z[i] = *max_element(s.begin(), s.end());
			}
		}
		for(int i = 0; i < m; i++) y[need[i].second] = i;
		for(int i = 0; i < m; i++)
		{
			long long bd = z[y[i]];
			long long sum = 0;
			for(int j = 0; j < k[i]; j++)
			{
				sum += adj[i][j];
			}
			for(int j = 0; j < k[i]; j++)
			{
				if(sum - adj[i][j] > bd * (k[i] - 1)) printf("0");
				
				else printf("1");
			}
		}
		printf("\n");
		for(int i = 0; i < m; i++) adj[i].clear();
	}
	return 0;
 }