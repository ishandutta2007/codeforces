#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
ll M;
ll a[MAXN];
ll b[MAXN];
int c2;
ll ans;

void fac (int x)
{
	for (int i = 1; i <= x; i++)
	{
		int temp = i;
		while (c2 > 0 && (temp % 2 == 0))
		{
			c2--;
			temp /= 2;
		}
		ans = (ans * temp) % M;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];
	cin >> M;
	
	c2 = 0; ans = 1;
	for (int i = 0; i < N; i++)
		if (a[i] == b[i])
			c2++;
	
	vector <ll> poss;
	for (int i = 0; i < N; i++)
	{
		poss.push_back (a[i]);
		poss.push_back (b[i]);
	}
	
	sort (poss.begin(), poss.end());
	
	int count = 1;
	for (int i = 1; i < 2 * N; i++)
	{
		if (poss[i] != poss[i-1])
		{
			fac (count);
			count = 0;
		}
		count++;
	}
	fac (count);
	
	cout << ans << "\n";
	return 0;
}