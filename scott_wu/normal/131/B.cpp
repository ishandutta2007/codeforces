#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
	ll nval[30];
	int N;
	
	for (int i = 0; i < 30; i++)
		nval[i] = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		nval[x+10]++;
	}
	
	ll ans = (nval[10] * (nval[10] - 1)) / 2;
	for (int i = 0; i < 10; i++)
		ans += nval[i] * nval[20-i];
	cout << ans << "\n";
	return 0;
}