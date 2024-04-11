#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

map < char, int > MP;
string s;

vector < int > a;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i ++)
		MP[s[i]] ++;
	for (map < char, int > :: iterator it = MP.begin(); it != MP.end(); it ++)
		a.push_back(it->second);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	if (a[0] == 6) cout << 1 << endl; else
	if (a[0] == 5) cout << 1 << endl; else
	if (a[0] == 4) cout << 2 << endl; else
	if (a[0] == 3 && a[1] == 3) cout << 2 << endl; else
	if (a[0] == 3 && a[1] == 2) cout << 3 << endl; else
	if (a[0] == 3) cout << 5 << endl; else
	if (a[0] == 2 && a[1] == 2 && a[2] == 2) cout << 6 << endl; else
	if (a[0] == 2 && a[1] == 2) cout << 8 << endl; else
	if (a[0] == 2) cout << 15 << endl; else
		cout << 30 << endl;

	return 0;
}