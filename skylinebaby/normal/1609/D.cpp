#include<bits/stdc++.h>
using namespace std;
int sz[1123];
int pa[1123];
pair<int, int> cal[1123];
int find(int x)
{
	if(pa[x] == x) return x;
	return pa[x] = find(pa[x]);
}
int merge(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if(a == b) return 1;
	if(sz[a] < sz[b])
	{
		pa[a] = b;
		sz[b] += sz[a];
	}
	else
	{
		pa[b] = a;
		sz[a] += sz[b];
	}
	return 0;
}
int main()
{
	int n, d;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++) sz[i] = 1, pa[i] = i;
	int waste = 0;
	for(int i = 0; i < d; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		waste += merge(x, y);
		int ans = 0;
		for(int j = 0; j < n; j++) cal[j] = make_pair(sz[j], j);
		sort(cal, cal + n);
		reverse(cal, cal + n);
		int pick = 0;
		int j = 0;
		set<int> s;
		while(pick <= waste)
		{
			int t = find(cal[j].second);
			if(s.find(t) == s.end())
			{
				s.insert(t);
				pick ++;
				ans += sz[t];
			}
			j ++;
			
		}
		printf("%d\n", ans - 1);
	}
	return 0; 
}