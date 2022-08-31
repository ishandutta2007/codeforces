#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
typedef long long ll;
const int MAXM = 100100;

int N, M;
int sz[2];
map <int, int> mmap[2];
vector <int> nlist[2];
//int nmin[2], nmax[2]; // # of min val and # of max val

ll ans, nans;

ll C3 (ll x)
{
	return ((ll) x * ((ll) x - 1) * ((ll) x - 2)) / 6;
}

ll C2 (ll x)
{
	return (x * (ll) (x - 1)) / 2;
}

void up (ll cnt, ll val)
{
	//cout << cnt << " " << val << "\n";
	
	if (val > ans)
	{
		ans = val;
		nans = cnt;
	}
	else if (val == ans)
		nans += cnt;
}

void run() // check for 3 or 2 of type 0
{
	nlist[0].clear();
	nlist[1].clear();
	
	for (int i = 0; i < 2; i++)
		for (map <int, int>::iterator it = mmap[i].begin(); it != mmap[i].end(); it++)
			nlist[i].push_back (it->first);
	
	map <int, int>::iterator it = mmap[0].begin();
	int lval = it->first, hval = it->first;
	while (it != mmap[0].end())
	{
		hval = it->first;
		it++;
	}
	
	ll nlo = mmap[0][lval], nhi = mmap[0][hval];
	if (lval == hval)
	{
		ll num = C3 (nlo);
		ll val = 0;
		
		up (num, val);
	}
	else
	{
		ll num = (nlo * nhi * (sz[0] - nlo - nhi));
		num += (C2 (nlo) * nhi) + (C2 (nhi) * nlo);
		ll val = hval - lval;
		
		up (num, val);
	}
	
	if (sz[0] >= 2 && sz[1] >= 1)
	{
		ll num = 0;
		ll val = N;
		
		
		it = mmap[1].begin();
		map<int,int>::iterator it2 = mmap[0].begin();
		ll tval = 0;
		while (it != mmap[1].end())
		{
			while (it2 != mmap[0].end() && it2->first < it->first)
			{
				tval += it2->second;
				it2++;
			}
			
			
			ll sval = 0;
			if (mmap[0].find (it->first) != mmap[0].end())
				sval = mmap[0][it->first];
			num += it->second * (C2 (sz[0]) - C2(tval) - C2 (sz[0] - tval - sval));
			it++;
		}
		
		if (num)
			up (num, val);
		else
		{
			int cloc = 0;
			while (cloc < nlist[1].size() - 1 && nlist[1][cloc+1] < lval)
				cloc++;
			
			if (nlist[1][cloc] < lval)
			{
				val = N - (lval - nlist[1][cloc]);
				num = mmap[1][nlist[1][cloc]] * (C2 (sz[0]) - C2 (sz[0] - nlo));
				up (num, val);
			}
			
			cloc = nlist[1].size() - 1;
			while (cloc > 0 && nlist[1][cloc-1] > hval)
				cloc--;
			if (nlist[1][cloc] > hval)
			{
				val = N - (nlist[1][cloc] - hval);
				num = mmap[1][nlist[1][cloc]] * (C2 (sz[0]) - C2 (sz[0] - nhi));
				up (num, val);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	sz[0] = sz[1] = 0;
	
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, f;
		cin >> s >> f;
		
		mmap[s][f];
		mmap[s][f]++;
		sz[s]++;
	}
	
	ans = -1;
	nans = 0;
	
	run();
	swap (mmap[0], mmap[1]);
	swap (sz[0], sz[1]);
	run();
	
	cout << nans << "\n";
	return 0;
}