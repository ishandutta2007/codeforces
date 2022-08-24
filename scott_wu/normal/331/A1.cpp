#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
int arr[MAXN];
ll ps[MAXN];
ll pneg[MAXN];
map <int, vector <int> > cmap;

ll res (int start, int end) //start..end inclusive
{
	return ps[end+1] - ps[start] - pneg[end] + pneg[start+1];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	ps[0] = pneg[0] = 0;
	for (int i = 0; i < N; i++)
	{
		ps[i+1] = ps[i] + arr[i];
		pneg[i+1] = pneg[i];
		if (arr[i] < 0)
			pneg[i+1] += arr[i];
	}
	
	for (int i = 0; i < N; i++)
		cmap[arr[i]].push_back (i);
	
	ll best = -1e16;
	int sloc = 0, eloc = 0;
	for (map <int, vector <int> >::iterator it = cmap.begin(); it != cmap.end(); it++)
	{
		int c = it->first;
		
		if (cmap[c].size() >= 2)
		{
			for (int i = 0; i < cmap[c].size() - 1; i++)
			{
				if (res (cmap[c][i], cmap[c][i+1]) > best)
				{
					best = res (cmap[c][i], cmap[c][i+1]);
					sloc = cmap[c][i];
					eloc = cmap[c][i+1];
				}
			}//best = max (best, res (cmap[c][i], cmap[c][i+1]));
			
			if (res(cmap[c][0], cmap[c][cmap[c].size() - 1]) > best)
			{
				best = res(cmap[c][0], cmap[c][cmap[c].size() - 1]);
				sloc = cmap[c][0];
				eloc = cmap[c][cmap[c].size() - 1];
			}
		}
	}
	
	vector <int> loc;
	for (int i = 0; i < N; i++)
		if (i < sloc || i > eloc || ((i > sloc) && (i < eloc) && arr[i] < 0))
			loc.push_back (i);
	
	cout << best << " " << loc.size() << "\n";
	for (int i = 0; i < loc.size(); i++)
		cout << loc[i] + 1 << " ";
	cout << "\n";
	return 0;
}