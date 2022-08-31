#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 3100;

int N;
vector <pair <int, bool> > edge[MAXN];
int tval, tbest;
int ans;

void flood (int cloc, int cval, int last)
{
	tbest = max (tbest, cval);
	if (cval < 0) cval = 0;
	
	for (int i = 0; i < edge[cloc].size(); i++)
	{
		if (edge[cloc][i].first != last)
		{
			if (edge[cloc][i].second)
				flood (edge[cloc][i].first, cval - 1, cloc);
			else
			{
				tval++;
				flood (edge[cloc][i].first, cval + 1, cloc);
			}
		}
	}
}

int main()
{
	ans = MAXN * MAXN;
	
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back (make_pair (b, true));
		edge[b].push_back (make_pair (a, false));
	}
	
	for (int i = 0; i < N; i++)
	{
		tval = tbest = 0;
		flood (i, 0, -1);
		//cout << tval << " " << tbest << "\n";
		ans = min (ans, tval - tbest);
	}
	
	cout << ans << "\n";
	return 0;
}