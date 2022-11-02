#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <set>

using namespace std;

string s;

int main()
{
	cin >> s;
	s += ',';
	set < int > a;
	int buf = 0;
	for (int i = 0; i < s.size(); i ++)
		if (s[i] == ',') a.insert(buf), buf = 0; else buf = buf * 10 + (s[i] - '0');
	for (int i = 1; i <= 1000; i ++)
		if (a.count(i) != 0)
		{
			int l = i;
			int r = i;
			while (a.count(r) != 0)
				a.erase(r), r ++;
			r --;
			if (l == r) printf("%d", l); else printf("%d-%d", l, r);
			if (!a.empty()) printf(",");
		}
	printf("\n");
	return 0;
}