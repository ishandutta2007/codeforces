#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	int s, n;
	cin >> s >> n;
	
	pair <int, int> drag[1100];
	for (int i = 0; i < n; i++)
		cin >> drag[i].first >> drag[i].second;
	
	sort (drag, drag + n);
	
	for (int i = 0; i < n; i++)
	{
		if (s <= drag[i].first)
		{
			cout << "NO\n";
			return 0;
		}
		s += drag[i].second;
	}
	cout << "YES\n";
	return 0;
}