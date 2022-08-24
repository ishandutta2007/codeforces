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

int N, M;
ll num[MAXN];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	ll hi = 0;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		ll W, H;
		cin >> W >> H;
		
		ll res = max (hi, num[W-1]);
		cout << res << "\n";
		hi = max (hi, res + H);
	}
	
	return 0;
}