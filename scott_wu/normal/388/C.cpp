#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int N;
vector <int> cposs;

int main()
{
	cin >> N;
	
	int a1 = 0, a2 = 0;
	
	int cval[110];
	for (int i = 0; i < N; i++)
	{	
		int nval; cin >> nval;
		for (int j = 0; j < nval; j++)
		{
			cin >> cval[j];
			if (j * 2 + 1 < nval)
				a1 += cval[j];
			else if (j * 2 + 1 > nval)
				a2 += cval[j];
			else
				cposs.push_back (cval[j]);
		}
	}
	
	sort (cposs.begin(), cposs.end());
	reverse (cposs.begin(), cposs.end());
	
	for (int i = 0; i < cposs.size(); i++)
		if (i % 2 == 0)
			a1 += cposs[i];
		else
			a2 += cposs[i];
	
	cout << a1 << " " << a2 << "\n";
	return 0;
}