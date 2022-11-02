#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int k, a, b;
string s;

int main()
{
	cin >> k >> a >> b;
	cin >> s;
	if (s.size() > k * b || s.size() < k * a)
	{
		printf("No solution\n");
		return 0;
	}
	int x = s.size() / k;
	int y = s.size() - x * k;
	int cur = -1;
	for (int i = 1; i <= k - y; i ++)
	{
		int f = 0;
		string buf = "";
		while (f < x)
			cur ++, buf += s[cur], f ++;
		cout << buf << endl;
	}
	for (int i = 1; i <= y; i ++)
	{
		int f = 0;
		string buf = "";
		while (f <= x)
			cur ++, buf += s[cur], f ++;
		cout << buf << endl;
	}
	return 0;
}