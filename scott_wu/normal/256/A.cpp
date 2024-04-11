#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 4100;

int N;
int seq[MAXN];
int clist[MAXN];
vector <int> poss;
vector <int> llist[MAXN];

int solve (int x, int y)
{
	if (llist[x][0] > llist[y][0])
		swap (x, y);
	
	int count = 1;
	int xloc = 0, yloc = 0;
	while (true)
	{
		count++;
		while (xloc < llist[x].size() && llist[x][xloc] < llist[y][yloc])
			xloc++;
		if (xloc == llist[x].size())
		{
			break;
		}
		
		count++;
		while (yloc < llist[y].size() && llist[y][yloc] < llist[x][xloc])
			yloc++;
		if (yloc == llist[y].size())
		{
			break;
		}
	}
	return count;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
		clist[i] = seq[i];
	}
	
	sort (clist, clist + N);
	
	for (int i = 0; i < N; i++)
	{
		if (i == 0 || clist[i] != clist[i-1])
			poss.push_back (clist[i]);
	}
	
	for (int i = 0; i < poss.size(); i++)
		for (int j = 0; j < N; j++)
			if (seq[j] == poss[i])
				llist[i].push_back (j);
	
	int ans = 1;
	for (int i = 0; i < poss.size(); i++)
	{
		ans = max (ans, (int) llist[i].size());
		for (int j = i + 1; j < poss.size(); j++)
			ans = max (ans, solve (i, j));
	}
	
	cout << ans << "\n";
	return 0;
}