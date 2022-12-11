#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

using namespace std;

struct sv{
	int pow, dmg, num;
};

string wd[1005];
int lw[1005];
int inp[1005];
bool use[1005];

int c[1005];
int col = 0;
string s;
string ans = "";
int n;
void rek(int a)
{
	if (col == 0) return;
	if (c[a] != 0)
	{
		c[a]--;
		wd[n - col] = s;
		lw[n - col] = a;
		col--;

		return;
	}
	s += '0';
	int l = s.length();
	rek(a + 1);
	s.resize(l - 1);
	s += '1';
	rek(a + 1);
	return;
}


int main()
{
	cin >> n;
	memset(c, 0, 1005);
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		inp[i] = w;
		c[w]++;
	}
	col = n;
	s = "";
	rek(0);
	if (col != 0)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	memset(use, 0, 1005);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!use[j] && lw[j] == inp[i])
			{
				cout << wd[j] << '\n';
				use[j] = true;
				break;
			}

	return 0;
}