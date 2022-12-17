#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <iomanip>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

typedef long long ll;

inline char gc()
{
	static char buf[524288],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,524288,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 1000005;
const int MAXV = 10000005;
const ll INF = 1e18;

int n;
int a[MAXN];
int cnt[MAXV][2];

ll ans,p1,p2;

int main()
{
	read(n);
	for (int i = 1;i <= n;i++)
	{
		read(a[i]);
		if (cnt[a[i]][0])
			cnt[a[i]][1] = i;
		else
			cnt[a[i]][0] = i;
	}
	ans = INF;
	for (int i = 1;i <= 10000000;i++)
	{
		ll flag = INF,P;
		for (int j = i;j <= 10000000;j += i)
		{
			if (cnt[j][1])
			{
				if (flag != INF)
				{
					if (flag * j / i < ans)
					{
						ans = flag * j / i;
						p1 = P;
						p2 = cnt[j][0];
					}
					break;
				}
				if ((ll)j * j / i < ans)
				{
					ans = (ll)j * j / i;
					p1 = cnt[j][0];
					p2 = cnt[j][1];
				}
				break;
			}
			if (cnt[j][0])
			{
				if (flag != INF)
				{
					if (flag * j / i < ans)
					{
						ans = flag * j / i;
						p1 = P;
						p2 = cnt[j][0];
					}
					break;
				}
				else
				{
					flag = j;
					P = cnt[j][0];
				}
			}
		}
	}
	if (p1 > p2)
		swap(p1,p2);
	cout << p1 << ' ' << p2 << endl;
	return 0;
}