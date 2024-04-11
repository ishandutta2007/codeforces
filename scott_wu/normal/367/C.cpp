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
const int MAXM = 200100;

ll N;
int M;
ll Q[MAXM], W[MAXM];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> Q[i] >> W[i];
	
	sort (W, W + M);
	reverse (W, W + M);
	
	//for (int i = 0; i < M; i++)
	//	cout << W[i] << " ";
	
	ll tot = 0;
	for (ll i = 1; i <= M; i++)
	{
		ll cval = (i * (i - 1)) / 2 + 1;
		if (i % 2 == 0)
			cval += i / 2 - 1;
		if (cval > N)
			break;
		
		tot += W[i-1];
	}
	
	cout << tot << "\n";
	return 0;
}