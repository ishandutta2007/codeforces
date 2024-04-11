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
const int MAXN = 55;

int N, M;
vector <int> vis[MAXN][MAXN]; // visions

vector <int> rloc;
vector <int> lloc;

int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			vis[i][j].push_back (-1);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;
		x--, y--;
		
		vis[x][y].clear();
		for (int j = 0; j < k; j++)
		{
			int t; cin >> t; t--;
			vis[x][y].push_back (t);
		}
	}
	
	bool found = false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (found) break;
			
			//cout << i << "x" << j << "\n";
			
			for (int k = 0; k < (int) vis[i][j].size() - 1; k++)
			{
				if (vis[i][j][k] == i && vis[i][j][k+1] == j)
				{
					bool bad = false;
					
					rloc.clear();
					for (int l = k + 1; l < vis[i][j].size(); l++)
						rloc.push_back (vis[i][j][l]);
					
					for (int l = 0; l < rloc.size() - 1; l++)
					{
						if (rloc.size() > 2 * N) break;
						
						if (vis[rloc[l]][rloc[l+1]].size() == 1 && vis[rloc[l]][rloc[l+1]][0] == -1)
						{
							//cout << rloc[l] << " " << rloc[l+1] << "\n";
							bad = true;
							break;
						}
						
						for (int m = 0; m < vis[rloc[l]][rloc[l+1]].size(); m++)
							rloc.push_back (vis[rloc[l]][rloc[l+1]][m]);
					}
					
					lloc.clear();
					for (int l = k; l >= 0; l--)
						lloc.push_back (vis[i][j][l]);
					
					for (int l = 0; l < lloc.size() - 1; l++)
					{
						//cout << lloc[l] << "\n";
						if (lloc.size() > 2 * N) break;
						
						if (vis[lloc[l+1]][lloc[l]].size() == 1 && vis[lloc[l+1]][lloc[l]][0] == -1)
						{
							//cout << lloc[l+1] << " " << lloc[l] << "\n";
							bad = true;
							break;
						}
						
						for (int m = vis[lloc[l+1]][lloc[l]].size() - 1; m >= 0; m--)
							lloc.push_back (vis[lloc[l+1]][lloc[l]][m]);
					}
					
					//cout << i << " " << j << " " << lloc.size() << " " << rloc.size() << "\n";
					
					if (!bad && lloc.size() + rloc.size() <= 2 * N)
					{
						found = true;
						
						cout << lloc.size() + rloc.size() << "\n";
						for (int l = lloc.size() - 1; l >= 0; l--)
							cout << lloc[l] + 1 << " ";
						for (int l = 0; l < rloc.size(); l++)
							cout << rloc[l] + 1 << " ";
						cout << "\n";
					}
					
					
					break;
				}
			}
		}
	
	if (!found)
		cout << "0\n";
	return 0;
}