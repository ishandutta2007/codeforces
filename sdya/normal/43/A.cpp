#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

map < string, int > A;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		string s;
		cin >> s;
		A[s] ++;
	}
	int best = 0;
	string res;
	for (map < string, int > :: iterator it = A.begin(); it != A.end(); it ++)
		if (it->second > best)
			best = it->second, res = it->first;
	cout << res << endl;
	return 0;
}