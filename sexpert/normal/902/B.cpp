#include <bits/stdc++.h>
using namespace std;

int n, rt;
vector<int> edges(11000, 0);
vector<int> colors(11000, 0);
vector<int> roots;

void pushRoots(int rt)
{
	int col;
	col = colors[rt];
	for(int i = rt + 1; i <= n; i++)
	{
		if(edges[i] == rt)
		{
			if(colors[i] != col) roots.push_back(i);
			else pushRoots(i);
		}
	}
}


int main()
{
	int count = 0;
	roots = {};
	roots.reserve(11000);
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		cin >> edges[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> colors[i];
	}
	roots.push_back(1);
	while(!roots.empty())
	{
		rt = roots[0];
		count++;
		roots.erase(roots.begin());
		pushRoots(rt);
	}
	printf("%d", count);
}