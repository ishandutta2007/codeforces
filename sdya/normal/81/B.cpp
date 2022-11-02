#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

char s[1100];
int n;

vector < string > a;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	gets(s);
	n = strlen(s);
	s[n] = ' ';
	string buf = "";
	for (int i = 0; i <= n; i ++)
		if (s[i] == ',')
		{
			if (buf != "") a.push_back(buf);
			a.push_back(","), buf = ""; 
		} else
			if (s[i] == '.')
			{
				if (buf != "") a.push_back(buf);
			 	i += 2, a.push_back("..."), buf = ""; 
			} else
				if (s[i] == ' ')
				{
					if (buf != "") a.push_back(buf);
					buf = ""; 
				} else
					if (s[i] >= '0' && s[i] <= '9') buf += s[i];

	string res = "";
	for (int i = 0; i < a.size(); i ++)
		if (a[i] == ",")
		{
			if (i + 1 == a.size()) res = res + a[i]; else
				res = res + a[i], res += ' ';
		} else
		if (a[i] == "...")
		{
			if (i == 0) res = res + a[i]; else
				if (res[res.size() - 1] == ' ') res = res + a[i]; else
					res += ' ', res = res + a[i];
		} else
		{
			if (i == 0) res = res + a[i]; else
				if (a[i - 1] != "," && a[i - 1] != "...") res += ' ', res = res + a[i]; else
					res = res + a[i];
		}

	cout << res << endl;
	return 0;
}