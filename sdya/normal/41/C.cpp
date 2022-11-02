#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

string s;
string res = "";

int main()
{
	cin >> s;
	bool have = false;
	res += s[0];
	for (int i = 1; i < s.size(); i ++)
		if (s[i] == 'd' && i + 3 < s.size() && s[i + 1] == 'o' && s[i + 2] == 't')
			res += '.', i += 2; else
			if (s[i] == 'a' && i + 1 < s.size() && s[i + 1] == 't' && !have)
				res += '@', i ++, have = true; else
				res += s[i];
	cout << res << endl;
	return 0;
}