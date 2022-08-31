#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, H;
pair <int, int> num[MAXN]; // val, index
int val[MAXN];
bool use[MAXN]; // true = 1, false = 2

int main()
{
	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i].first;
		num[i].second = i;
		use[i] = true;
	}
	sort (num, num + N);
	
	if (N == 2)
	{
		cout << "0\n";
		cout << "1 1\n";
		return 0;
	}
	
	for (int i = 0; i < N; i++)
		val[i] = num[i].first;
	
	int best = 0, lval = (val[N-1] + val[N-2]) - (val[0] + val[1]);
	int nval = max (val[N-1] + val[N-2], val[N-1] + val[0] + H) - min (val[1] + val[2], val[0] + val[1] + H);
	if (nval < lval)
	{
		lval = nval;
		best = N-1;
	}
	
	nval = max (val[N-1] + val[N-2], val[N-1] + val[1] + H) - min (val[0] + val[2], val[0] + val[1] + H);
	if (nval < lval)
	{
		lval = nval;
		best = 1;
	}
	
	nval = val[N-1] + val[N-2] + H - min (val[0] + val[N-1], min (val[1] + val[2], val[0] + val[1] + H));
	if (nval < lval)
	{
		lval = nval;
		best = N - 2;
	}
	
	for (int i = 2; i < N - 2; i++)
	{
		nval = max (val[N-1] + val[N-2], val[N-1] + val[i] + H) - min (val[1] + val[2], min (val[0] + val[1] + H, val[0] + val[i+1]));
		if (nval < lval)
		{
			lval = nval;
			best = i;
		}
	}
	
	for (int i = 1; i <= best; i++)
		use[num[i].second] = false;
	
	cout << lval << "\n";
	for (int i = 0; i < N; i++)
	{
		if (use[i]) cout << "1";
		else cout << "2";
		if (i < N - 1) cout << " ";
	}
	cout << "\n";
	return 0;
}