#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector <int> plist;

bool prime (int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 2; i <= N; i++)
		if (prime (i))
			plist.push_back (i);
	
	int ans = 0;
	for (int i = 0; i < plist.size(); i++)
	{
		for (int j = 0; j < plist.size() - 1; j++)
			if (plist[i] == plist[j] + plist[j+1] + 1)
				ans++;
	}
	if (ans >= K)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}