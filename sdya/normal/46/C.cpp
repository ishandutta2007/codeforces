#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int n;
string s;

int main()
{
	cin >> n;
	cin >> s;
	int h = 0;
	for (int i = 0; i < s.size(); i ++)
		if (s[i] == 'H') h ++;
	string buf = "";
	for (int i = 0; i < h; i ++)
		buf += 'H';
	for (int i = 0; i < s.size() - h; i ++)
		buf += 'T';

	int dif = 1000000;
	for (int k = 0; k < s.size(); k ++)
	{
		int t = 0;
		for (int i = 0; i < s.size(); i ++)
			if (s[i] != buf[(i + k) % s.size()]) t ++;
		dif = min(dif, t);
	}
	printf("%d\n", dif / 2);
	return 0;
}