#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXT = 100100;

int N, M;
int seq[2 * MAXT];
vector <pair <int, int> > s; // # elem, format (x or -l)
ll ssize;

int main()
{
	ios_base::sync_with_stdio(0);
	ssize = 0;
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int type; cin >> type;
		if (type == 1)
		{
			int x;
			cin >> x;
			if (ssize < MAXT)
				seq[ssize] = x;
			s.push_back (make_pair (-1, x));
			ssize++;
		}
		else
		{
			ll l, c;
			cin >> l >> c;
			
			if (ssize < MAXT)
			{
				for (int i = ssize; i < min ((ll) MAXT, ssize + l * c); i++)
					seq[i] = seq[(i - ssize) % l];
			}
			s.push_back (make_pair (l * c, l));
			ssize += l * c;
		}
	}
	
	int N; cin >> N;
	ll ctot = 0;
	int cloc = 0;
	for (int i = 0; i < N; i++)
	{
		ll t; cin >> t;
		t--;
		
		while (ctot + abs (s[cloc].first) <= t)
		{
			ctot += abs (s[cloc].first);
			cloc++;
		}
		
		if (s[cloc].first == -1)
			cout << s[cloc].second;
		else
			cout << seq[(t - ctot) % (ll) s[cloc].second];
		if (i < N - 1)
			cout << " ";
	}
	cout << "\n";
	return 0;
}