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
const int MAXN = 1000100;
const int MAXM = 7100;
const int MAXB = 20;

int N, M;
int next[MAXB + 2][MAXN];
int flo[MAXN], fhi[MAXN];

vector <int> l[MAXM], r[MAXM], x[MAXM];
//int nb;

int s[MAXM];
int ns;

int main()
{
	ios_base::sync_with_stdio(0);
	
	next[0][0] = 0;
	next[0][1] = 1;
	for (int i = 2; i < MAXN; i++)
	{
		int l = next[0][i-1];
		if ((l & (l - 1)) || (l == next[0][i-2]))
			next[0][i] = l + 1;
		else
			next[0][i] = l;
	}
	
	for (int i = 1; i < MAXN; i++)
	{
		if (next[0][i] != next[0][i-1])
		{
			flo[next[0][i]] = i;
			fhi[next[0][i-1]] = i - 1;
		}
	}
	
	for (int i = 0; i < MAXB; i++)
		for (int j = 1; j < MAXN; j++)
			next[i+1][j] = next[i][next[i][j]];
	
	cin >> N >> M;
	
	//nb = 0;
	for (int m = 0; m < M; m++)
	{
		int type; cin >> type;
		
		if (type == 1)
		{
			int t, lx, rx, xx;
			cin >> t >> lx >> rx >> xx;
			
			l[t].push_back (lx);
			r[t].push_back (rx);
			x[t].push_back (xx);
			//cin >> t[nb] >> l[nb] >> r[nb] >> x[nb];
			//nb++;
		}
		else
		{
			int t, vlo, vhi;
			cin >> t >> vlo;
			vhi = vlo;
			
			ns = 0;
			for (int i = t; i <= N; i++)
			{
				for (int j = 0; j < l[i].size(); j++)
				{
					if (l[i][j] <= vhi && vlo <= r[i][j])
					{
						s[ns] = x[i][j];
						ns++;
					}
				}
				vlo = flo[vlo];
				vhi = fhi[vhi];
			}
			
			if (ns == 0)
			{
				cout << "0\n";
				continue;
			}
			
			sort (s, s + ns);
			int ans = 1;
			for (int i = 1; i < ns; i++)
				if (s[i] != s[i-1])
					ans++;
			cout << ans << "\n";
		}
	}
	
	return 0;
}