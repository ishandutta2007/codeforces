#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
const int MAXD = 3100;
const int MAXN = 100100;

int N;
int x1[MAXN], x2[MAXN], y1[MAXN], y2[MAXN];

int hs[MAXD][MAXD];

bool cover[MAXD][MAXD];
int vps[MAXD][MAXD]; // rows (fixed y)
int hps[MAXD][MAXD]; // columns (fixed x)

vector <int> ans;

int main()
{
	for (int i = 0; i < MAXD; i++)
		for (int j = 0; j < MAXD; j++)
		{
			cover[i][j] = false;
			hs[i][j] = vps[i][j] = hps[i][j] = 0;
		}
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		
		for (int j = x1[i]; j < x2[i]; j++)
			for (int k = y1[i]; k < y2[i]; k++)
				cover[j][k] = true;
		
		for (int j = x1[i] + 1; j <= x2[i]; j++)
			vps[j][y1[i]] = vps[j][y2[i]] = 1;
		for (int j = y1[i] + 1; j <= y2[i]; j++)
			hps[x1[i]][j] = hps[x2[i]][j] = 1;
	}
	
	for (int i = 3000; i >= 0; i--)
		for (int j = 3000; j >= 0; j--)
		{
			if (!cover[i][j])
				hs[i][j] = 0;
			else
				hs[i][j] = 1 + min (hs[i+1][j], min (hs[i][j+1], hs[i+1][j+1]));
		}
	
	for (int i = 0; i < MAXD; i++)
		for (int j = 0; j < MAXD - 1; j++)
		{
			hps[i][j+1] += hps[i][j];
			vps[j+1][i] += vps[j][i];
		}
	
	int xans = -1, yans = -1, x2ans = -1, y2ans = -1;
	
	for (int i = 0; i < N; i++)
	{
		if (xans != -1)
			break;
		
		
		int xstart = x1[i], ystart = y1[i];
		
		int lo = 0, hi = hs[xstart][ystart];
		while (lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			if (vps[xstart+mid][ystart] - vps[xstart][ystart] == mid &&
				hps[xstart][ystart+mid] - hps[xstart][ystart] == mid)
				lo = mid;
			else
				hi = mid - 1;
		}
		
		for (int j = 1; j <= lo; j++)
		{
			if ((vps[xstart+j][ystart+j] - vps[xstart][ystart+j] == j) && 
				(hps[xstart+j][ystart+j] - hps[xstart+j][ystart] == j))
			{
				xans = xstart;
				yans = ystart;
				x2ans = xstart + j;
				y2ans = ystart + j;
				break;
			}
		}
	}
	
	if (xans == -1)
	{
		cout << "NO\n";
		return 0;
	}
	
	ans.clear();
	for (int i = 0; i < N; i++)
		if (xans <= x1[i] && x2[i] <= x2ans && yans <= y1[i] && y2[i] <= y2ans)
			ans.push_back (i + 1);
	
	cout << "YES " << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}