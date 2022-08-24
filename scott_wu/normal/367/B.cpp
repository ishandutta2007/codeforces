#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 200100;

int N, M, P;
int a[MAXN];
int b[MAXN];

int acount[MAXN];
int bcount[MAXN];

map <int, int> cmap;
vector <int> ans;

int main()
{
	cin >> N >> M >> P;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < M; i++)
		cin >> b[i];
	
	sort (b, b + M);
	int nb = 0;
	
	for (int i = 0; i < M; i++)
		if (cmap.find (b[i]) == cmap.end())
		{
			cmap[b[i]] = nb;
			nb++;
		}
	
	for (int i = 0; i < MAXN; i++)
		acount[i] = bcount[i] = 0;
	
	for (int i = 0; i < M; i++)
		bcount[cmap[b[i]]]++;
	
	for (int i = 0; i < P; i++)
	{
		if (i + (M - 1) * (ll) P < N)
		{
			for (int j = 0; j < nb; j++)
				acount[j] = 0;
			
			int noff = nb, nbad = 0;
			
			for (int j = i; j < N; j += P)
			{
				int nval = a[j];
				
				if (cmap.find (nval) == cmap.end())
					nbad++;
				else
				{
					int x = cmap[nval];
					acount[x]++;
					
					if (acount[x] == bcount[x]) noff--;
					else if (acount[x] == bcount[x] + 1) noff++;
				}
				
				if (noff == 0 && nbad == 0)
					ans.push_back (j - (M - 1) * P);
				
				if (j >= i + (M - 1) * P)
				{
					nval = a[j - (M - 1) * P];
					if (cmap.find (nval) == cmap.end())
						nbad--;
					else
					{
						int x = cmap[nval];
						acount[x]--;
					
						if (acount[x] == bcount[x]) noff--;
						else if (acount[x] == bcount[x] - 1) noff++;
					}
				}
			}
		}
	}
	
	sort (ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << " ";
	cout << "\n";
	return 0;
}