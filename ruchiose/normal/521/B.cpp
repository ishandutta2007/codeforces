// Author: Ruchiose, on zhzxpc
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

#define i64 long long

#include<set>
#include<map>

const int MAXN = 100010;

map<pair<int,int>,int> EXI;
set<int> tomove;

bool isExist(int x, int y)
{
	if (EXI.count(make_pair(x, y)))
		return true;
	else
		return false;
}

bool isRemovable(int x, int y)
{
	int dx1, dx2;
	fortodo(dx1, -1, 1)
		if (isExist(x + dx1, y + 1))
			{
				int count = 0;
				fortodo(dx2, -1, 1)
					if (isExist(x + dx1 + dx2, y))
						count++;
				if (count == 1)
					return false;
			}
	return true;
}

void recheckRemovablity(int x, int y)
{
	if (!isExist(x, y)) return;
	if (isRemovable(x, y))
		tomove.insert(EXI[make_pair(x, y)]);
	else
		tomove.erase(EXI[make_pair(x, y)]);
}

const i64 MOD = 1000000009;

int N, X[MAXN], Y[MAXN];
i64 ans;

int main()
{
	scanf("%d", &N);
	int i;
	fortodo(i, 0, N - 1)
		scanf("%d%d", &X[i], &Y[i]);
	ans = 0;
	tomove.clear();
	EXI.clear();
	fortodo(i, 0, N - 1)
		EXI.insert(make_pair(make_pair(X[i], Y[i]), i));
	fortodo(i, 0, N - 1)
		recheckRemovablity(X[i], Y[i]);
	fortodo(i, 1, N)
		{
			set<int>::iterator it;
			if (i % 2 == 0)
				it = tomove.begin();
			else
				{
					it = tomove.end();
					it--;
				}
			int c = *it;
			ans = (ans * N + c) % MOD;
			EXI.erase(make_pair(X[c], Y[c]));
			tomove.erase(c);
			recheckRemovablity(X[c] - 2, Y[c]);
			recheckRemovablity(X[c] - 1, Y[c]);
			recheckRemovablity(X[c] + 1, Y[c]);
			recheckRemovablity(X[c] + 2, Y[c]);
			recheckRemovablity(X[c] - 1, Y[c] - 1);
			recheckRemovablity(X[c], Y[c] - 1);
			recheckRemovablity(X[c] + 1, Y[c] - 1);
		}
	cout << ans << endl;
	return 0;
}