#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define s second
#define f first
#define ull unsigned long long
#define ll long long

const int nmax = (int)1e5 + 10, inf = (int)1e9 + 7;

int a[101], b[101], f[101], n, q, ff, l, r;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		f[a[i]] = i;
	}
	f[n + 1] = 101;
	cin >> q;
	for(int i = 0; i < q; ++i)
	{
		cin >> ff >> l >> r;
		if(ff == 1)
		{
			int res = 0;
			for(int i = l; i <= r; )
			{
				++res;
				while(f[i] < f[i + 1] && i <= r)
					++i;
				++i;
			}
			cout << res << endl;
		}
		else
		{
			swap(a[l], a[r]);
			f[a[l]] = l;
			f[a[r]] = r;
		}
	}
}