#include <iostream>

using namespace std;
const int MAXN = 100100;

int N;
int nval[MAXN];

void solve (int cloc)
{
	if (~nval[cloc])
		return;
	nval[cloc] = -2;
	
	int left = (2 * cloc) % N, right = (2 * cloc + 1) % N;
	int op = (cloc + N / 2) % N;
	
	if (!~nval[left] && !~nval[right])
	{
		nval[cloc] = left;
		solve (left);
		
		if (!~nval[op])
		{
			nval[cloc] = right;
			solve (right);
		}
	}
	else
	{
		if (~nval[right])
		{
			nval[cloc] = left;
			solve (left);
		}
		else
		{
			nval[cloc] = right;
			solve (right);
		}
	}
	
	//cout << cloc << " " << nval[cloc] << "\n";
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		nval[i] = -1;
	
	cin >> N;
	if (N % 2 == 1)
	{
		cout << "-1\n";
		return 0;
	}
	
	solve (0);
	int cur = 0;
	for (int i = 0; i <= N; i++)
	{
		cout << cur << " ";
		cur = nval[cur];
	}
	cout << "\n";
	return 0;
}