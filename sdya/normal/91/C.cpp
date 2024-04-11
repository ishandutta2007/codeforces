#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;
typedef long long LL;

#define MOD 1000000009
#define N 111000
int n,m;
int p[N],r[N];

int getset(int v)
{
	return p[v]==v ? v : (p[v]=getset(p[v]));
}

void mergeset(int v, int u)
{
	if (r[v]<r[u])
		p[v]=u;
	else
	{
		p[u]=v;
		r[v]+=r[u]==r[v];
	}
}


int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++) p[i]=i,r[i]=0;
	LL res = 1;
	for (int i = 0; i < m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		x = getset(x);
		y = getset(y);
		if (x==y)
		{
			res = (res*2) % MOD;
		}
		else
			mergeset(x,y);
		printf("%d\n",(int)((res+MOD-1)%MOD));
	}
	return 0;
}