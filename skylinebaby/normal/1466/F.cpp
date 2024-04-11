#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int sz[512345];
int papa[512345];
int find(int x)
{
	if(papa[x] == x) return x;
	return papa[x] = find(papa[x]);
}
void merge(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if(sz[a] > sz[b]) swap(a, b);
	sz[b] += sz[a];
	papa[a] = b;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= m; i++) 
	{
		sz[i] = 1;
		papa[i] = i;
	}
	vector<int> ans;
	long long eheh = 1;
	for(int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		if(k == 1)
		{
			int x;
			scanf("%d", &x);
			x--;
			if(find(x) == find(m))
			{
				continue;
			}
			merge(x, m); 
			ans.push_back(i);
			eheh *= 2;
			eheh %= mod;
		}
		if(k == 2)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--, y--;
			if(find(x) == find(y))
			{
				continue;
			}
			merge(x, y); 
			ans.push_back(i);		
			eheh *= 2;
			eheh %= mod;
		}
	}
	printf("%lld %d\n", eheh, (int)ans.size());
	for(int i = 0; i < (int)ans.size(); i++)
	{
		printf("%d ", ans[i] + 1);
	}
	printf("\n");
	return 0;
 }