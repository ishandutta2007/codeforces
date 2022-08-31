#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map> 
#define maxn 200005
#define ll long long
#define ld double
#define pr pair<int, int>
#define mp make_pair 
#define mod 998244353
using namespace std;
map<ll, int> id;
vector<pr > ts[maxn];
map<ll, int> ins;
int gcd(int x, int y)
{
	if(!y) return x;
	return gcd(y, x % y);
}
ll ch(int a, int b)
{
	return a * 1000000ll + b;
}
int main()
{
	int q;
	scanf("%d", &q);
	int idcnt = 0;
	int tot = 0;
	for(int i = 0; i < q; i++)
	{
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(t == 1)
		{
			tot++;
			ll n1 = 1ll * x * x + 1ll * y * y;
			if(!id[n1]) id[n1] = ++idcnt;
			int nid = id[n1];
			int ng = gcd(x, y);
			ins[ch(x / ng, y / ng)]++;
			for(int j = 0; j < ts[nid].size(); j++)
			{
				int nx = x + ts[nid][j].first, ny = y + ts[nid][j].second;
				int ng = gcd(nx, ny);
				ins[ch(nx / ng, ny / ng)] += 2;
			}
			ts[nid].push_back(mp(x, y));
		}
		else if(t == 2)
		{
			tot--;
			ll n1 = 1ll * x * x + 1ll * y * y;
			if(!id[n1]) id[n1] = ++idcnt;
			int nid = id[n1];
			int ng = gcd(x, y);
			ins[ch(x / ng, y / ng)]--;
			pr n2 = mp(x, y);
			int pl = 0;
			for(int j = 0; j < ts[nid].size(); j++)
			{
				if(ts[nid][j] == n2) pl = j;
				else
				{
					int nx = x + ts[nid][j].first, ny = y + ts[nid][j].second;
					int ng = gcd(nx, ny);
					ins[ch(nx / ng, ny / ng)] -= 2;
				}
			}
			int ncnt = 0;
			for(int j = 0; j < ts[nid].size(); j++)
				if(j != pl) ts[nid][ncnt++] = ts[nid][j];
			ts[nid].resize(ncnt);
		}
		else 
		{
			int ng = gcd(x, y);
			printf("%d\n", tot - ins[ch(x / ng, y / ng)]);
		}
	}
	return 0;
}