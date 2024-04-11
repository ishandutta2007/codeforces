#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main()
{
	int N; cin >> N;
	int val[110];
	
	for (int i = 0; i < N; i++)
		cin >> val[i];
	sort (val, val + N);
	
	bool use[110];
	for (int i = 0; i < N; i++)
		use[i] = false;
	
	int res = 0, tot = 0;
	while (tot < N)
	{
		res++;
		
		int cval = 0;
		for (int i = 0; i < N; i++)
			if (!use[i])
				if (val[i] >= cval)
				{
					use[i] = true;
					cval++;
					tot++;
				}
	}
	
	cout << res << "\n";
	return 0;
}