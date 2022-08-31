#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio (0);
	
	ll ans = 0;
	int ctot = 0;
	
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int k; cin >> k;
		
		if (k == 0)
		{
			ans += ctot;
		}
		else
			ctot++;
	}
	cout << ans << "\n";
	return 0;
}