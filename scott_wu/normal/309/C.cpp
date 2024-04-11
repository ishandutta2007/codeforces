#include <iostream>
#include <algorithm>

using namespace std;
const int MAXB = 31;

int N, M;
int acount[MAXB];
int bcount[MAXB];

int main()
{
	for (int i = 0; i < MAXB; i++)
		acount[i] = bcount[i] = 0;
	ios_base::sync_with_stdio (0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		for (int j = 0; j < MAXB; j++)
			if (x & (1 << j))
				acount[j]++;
	}
	
	for (int i = 0; i < M; i++)
	{
		int x; cin >> x;
		bcount[x]++;
	}
	
	int res = 0;
	int cloc = 0;
	for (int i = 0; i < MAXB; i++)
	{
		int tot = 0;
		while (acount[i] > 0 && cloc <= i)
		{
			int nleft = ((1 << i) - tot) / (1 << cloc);
			if (nleft >= bcount[cloc])
			{
				res += bcount[cloc];
				tot += bcount[cloc] * (1 << cloc);
				cloc++;
			}
			else
			{
				res += nleft;
				bcount[cloc] -= nleft;
				acount[i]--;
				tot = 0;
			}
		}
	}
	cout << res << "\n";
	return 0;
}