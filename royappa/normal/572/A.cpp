#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include <string.h>

using namespace std;



int main()
{
	int na, nb, k, m;

	cin >> na >> nb;
	cin >> k >> m;
	vector<int> va(na), vb(nb);
	for (int i = 0; i < na; i++)
		cin >> va[i];
	for (int i = 0; i < nb; i++)
		cin >> vb[i];

	if (vb[nb-m] > va[k-1])
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
	return 0;
}