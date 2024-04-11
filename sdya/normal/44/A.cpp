#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

set < pair < string, string > > S;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		string s1, s2;
		cin >> s1;
		cin >> s2;
		S.insert(make_pair(s1, s2));
	}
	printf("%d\n", S.size());
	return 0;
}